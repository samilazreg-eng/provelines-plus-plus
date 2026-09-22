# Episode 2 — The Script from Another Era

> The code had not suddenly stopped working. The world around it had moved on.

[Episode 1](01-archaeology-begins.md) established the terrain. ProVeLines was a
small verification engine surrounded by twenty years of embedded dependencies,
generated parsers and locally preserved files that Git could not reproduce.

This episode returns to the build errors we deliberately left uninterpreted.

The objective is not simply to make them disappear. Each error marks a boundary
between the environment in which the project was developed and the environment
in which we are trying to recover it. If we read them in order, the failed build
becomes a history of C tooling in miniature.

## The script that came from another era

It began with three strange messages in WSL:

```text
$'clear\r': command not found
cd: $'./parser/\r': No such file or directory
syntax error near unexpected token `fi'
```

At first glance, the script looked corrupted. Yet `clear`, `cd` and `fi` were
spelled correctly. The culprit was invisible: Windows CRLF line endings.

Bash read the carriage return, `\r`, as part of each token. It did not look for
the command `clear`; it looked for the improbable command `clear\r`. It did not
look for `./parser/`; it looked for a directory whose name ended with a hidden
character.

Once the shell files were normalized to LF, the fog lifted and the build could
finally begin.

It did not get far.

## LTL2BA and the variables that used to merge

LTL2BA reached the linker, which reported that two symbols, `rank` and
`scc_stack`, were defined more than once.

The sources confirmed the collision:

```c
/* generalized.c */
GScc *scc_stack;
int *fin, *final, rank, scc_id, scc_size, *bad_scc;

/* buchi.c */
BScc *scc_stack;
int accept, bstate_count = 0, btrans_count = 0, rank;
```

These are tentative definitions: uninitialized global variables emitted by two
translation units under the same external names. Older GCC toolchains commonly
placed such definitions in a shared “common” block. The linker merged them
instead of rejecting the program.

GCC 10 changed the default from `-fcommon` to `-fno-common`. Under the new
default, each tentative definition is emitted as a real definition, and the
linker correctly reports that the program defines the same external symbol more
than once.

A diagnostic build with:

```text
-fcommon
```

allowed the historical LTL2BA source to link again. That experiment did not
make the duplicate definitions a good interface. It confirmed their origin.

The long-term correction would give the two internal algorithms distinct
symbols or make their state private to their own source files. The compatibility
flag temporarily reconstructs the old linker's behaviour; it does not remove
the ambiguity.

One dependency had crossed the first bridge.

CUDD was waiting on the other side.

## Nine headers that were really lost symbolic links

CUDD failed differently. Files such as `include/util.h` contained no C
declarations at all. Their complete content was a relative path:

```text
../util/util.h
```

The other files followed the same pattern:

```text
../cudd/cudd.h
../cudd/cuddInt.h
../obj/cuddObj.hh
../dddmp/dddmp.h
../epd/epd.h
../mnemosyne/mnemosyne.h
../mtr/mtr.h
../st/st.h
../util/util.h
```

They looked nonsensical as headers because they had never been intended to be
regular files. CUDD's own `setup.sh` explains their original form:

```sh
CREATE="ln -s"

$CREATE ../cudd/cudd.h .
$CREATE ../cudd/cuddInt.h .
$CREATE ../epd/epd.h .
$CREATE ../dddmp/dddmp.h .
$CREATE ../mtr/mtr.h .
$CREATE ../obj/cuddObj.hh .
$CREATE ../st/st.h .
$CREATE ../util/util.h .
$CREATE ../mnemosyne/mnemosyne.h .
```

On the original Unix filesystem, opening `include/util.h` followed a symbolic
link to the real header. Somewhere between the original tree, its import into
Git and its use through Windows, the links were flattened. Their destinations
survived only as one-line text payloads.

GCC then attempted to parse `../util/util.h` as a C expression. The resulting
errors were spectacular but secondary: `FILE`, `NULL`, `ALLOC` and many other
identifiers appeared to have vanished because the real declarations had never
been included.

Nine false headers were identified. Replacing them experimentally with portable
forwarding headers restored their intended routing:

```c
#include "../util/util.h"
```

Unlike symbolic links, this relationship is explicit in the source language
and survives ordinary Windows filesystems, archive tools and Git checkouts.

CUDD could now build its static libraries.

The build had crossed Windows-versus-Unix line endings, old-versus-new linker
defaults, and symbolic-links-versus-ordinary-files. Only then did it reach
ProVeLines itself.

## A project living between two generations of C

The historical final command did not select a complete C language dialect:

```bash
gcc -fgnu89-inline ...
```

It specified the old GNU behaviour of `inline`, but otherwise inherited the
compiler's default language mode. That was a stable assumption only while the
compiler installed on the developers' machines remained similar to the one they
had used before.

The source itself contains evidence from both sides of a language transition.

Some parts retain old C habits:

- functions are called before a declaration is visible;
- declarations such as `extern int yyparse();` omit parameter information;
- headers do not always publish the functions implemented by their source file;
- source files rely on unrelated includes to make library functions visible.

Other parts require newer syntax, including loop-local declarations:

```c
for (int i = 0; i < samples; i++) {
```

Compiling as GNU89 accommodates several old declaration patterns but rejects
those loops. Compiling with GCC 15's modern default accepts the loops but gives
new, stricter meanings to old-style function declarations and rejects calls
that previous compilers could not type-check accurately.

The code wants neither the absolute past nor the compiler's present default.
The diagnostic equilibrium is GNU C99 with the historical GNU89 inline
semantics:

```text
-std=gnu99 -fgnu89-inline
```

This is not an arbitrary pair of flags. GNU99 accepts the syntax demonstrably
used by the program, while `-fgnu89-inline` preserves the linkage convention
already requested by the original build.

The choice makes an implicit environmental dependency explicit. It also reveals
the next problem instead of solving it.

## The clock that existed only by accident

Reproducing the recovery on another environment exposed a smaller failure with
a remarkably precise message:

```text
main.c:54:16: error: storage size of ‘_profileTimeBegin’ isn’t known
main.c:54:35: error: storage size of ‘_profileTimeEnd’ isn’t known
```

The declarations looked harmless:

```c
struct timeval _profileTimeBegin, _profileTimeEnd;
```

They were not. Defining an object requires the compiler to know the complete
size and layout of its type. `main.c` used `struct timeval` but never included
the POSIX header that defines it.

The profiler block in `main.h` made the assumption more visible:

```c
#ifdef PROFILER
    #include <time.h>
    /* ... struct timeval begin; ... */
#endif
```

`<time.h>` provides facilities such as `time_t`, `struct tm`, `time()` and
`strftime()`. On Linux and macOS, `struct timeval` and `gettimeofday()` belong
to `<sys/time.h>`.

Why had the earlier build progressed past this line? Another header happened to
make the definition visible transitively. Change the platform, dependency
version, feature selection or include order, and the borrowed declaration
vanishes. One environment therefore compiled the file by accident while
another correctly exposed the missing dependency.

The repair was deliberately boring:

```c
#include <sys/time.h>
```

`main.c` now includes it because it instantiates `struct timeval`. The profiler
block includes it because it also stores that type and calls `gettimeofday()`.
The correction was checked with GCC 15 both with and without `PROFILER` enabled.

No timing algorithm changed. We did not fix time. We included it.

This tiny failure captures a large part of build recovery: “it compiled here”
does not prove that a source file declares its real dependencies. A translation
unit should include what it uses, and a header should be able to provide the
types and functions behind the interface it publishes. Transitive includes are
not dependencies; they are coincidences with good public relations.

## Eleven declarations between the source and a binary

GCC 14 and later no longer accept calls to undeclared functions by default. A
diagnostic run therefore temporarily downgraded that one error class:

```text
-Wno-error=implicit-function-declaration
```

With the dialect fixed and the eleven undeclared calls tolerated, the compiler
produced a genuine 64-bit Linux executable in `/tmp` without changing the
product sources.

That binary was useful as evidence, not as a finished repair.

Most of the eleven diagnostics were modest interface omissions:

- `main.c` calls `SelectStream` and `PutSeed` without including the RNGS header;
- `execution.c` calls `hashState` without seeing its declaration;
- utility files use `strcmp` or `memcmp` without including `<string.h>`;
- some functions exist in a source file but were never published by the
  corresponding public header;
- generated parser code calls project helpers before any prototype is visible.

The correct destination is clear: every function should have one authoritative
prototype in an appropriate header, and every caller should include that
header. A compiler switch can expose this inventory, but it cannot supply the
missing type information.

One warning, however, was not a modest omission.

It exposed a real disagreement between the parser and scanner.

## The extra argument between Bison and Flex

The Flex scanner declares a two-argument function:

```c
#define YY_DECL \
    int yylex(YYSTYPE *yylval_param, struct symTabNode_ **globalSymTab)
```

The grammar separately asks Bison to pass two lexical parameters:

```bison
%lex-param {YYSTYPE * yylval}
%lex-param {struct symTabNode_* * globalSymTab}
```

But the generated pure parser already passes the semantic value automatically.
As a result, the retained parser calls `yylex` with three arguments:

```c
yylex(&yylval, yylval, globalSymTab)
```

The scanner still accepts only two:

```c
yylex(&yylval, globalSymTab)
```

The semantic value has been added twice. More importantly, the second argument
received by the scanner is no longer necessarily the symbol table pointer it
expects.

Old declarations without prototypes concealed this mismatch. The compiler knew
that a function named `yylex` existed, but not enough about its parameter list
to compare caller and callee. GCC 15's stricter interpretation made the
disagreement visible.

This is the boundary where “make the warning disappear” becomes actively
dangerous. Downgrading the diagnostic may produce an executable, but the
generated parser and scanner can still disagree at runtime.

The repair must happen at the source of generation:

1. remove the redundant semantic-value lexical parameter from `promela.y`;
2. retain the symbol-table parameter required by the scanner;
3. regenerate the Bison parser;
4. verify that the generated call and Flex declaration have the same signature;
5. preserve the regenerated files only after their provenance is recorded.

The old generated parser is not merely noisy. It preserves the exact generator
contract that needs to be corrected.

## The compiler timeline explains the failures

The repository and its dependencies point to a development period around
2010–2013. A typical compiler in that environment belonged to the GCC 4.x
series. GCC 4.8 used `gnu90` by default and accepted selected later-language
features as GNU extensions. That was a particularly forgiving environment for
a project mixing old declaration conventions with newer syntax.

The build script did not freeze that environment. It inherited whatever the
installed compiler considered its default.

While ProVeLines remained still, that default moved repeatedly:

| Period | GCC evolution | Consequence for ProVeLines |
| --- | --- | --- |
| 2010–2013 | GCC 4.x defaults to `gnu90` and accepts numerous GNU extensions | Mixed-era C and incomplete interfaces can still pass through the toolchain |
| 2015 | GCC 5 changes the default from `gnu89` to `gnu11` | Inline and language semantics change even though `build.sh` does not |
| 2020 | GCC 10 enables `-fno-common` by default | LTL2BA's duplicate `rank` and `scc_stack` definitions become linker errors |
| 2024 | GCC 14 promotes implicit function declarations to errors | Missing ProVeLines prototypes now stop compilation |
| 2025 | GCC 15 changes the default from `gnu17` to `gnu23` | `int yyparse();` now means no parameters, exposing incompatible calls immediately |

### GCC 4.8 — a permissive starting point

The GCC 4.8 manual records `gnu90` as the default when no dialect option is
provided. It also says that some C99 and C11 features are accepted as extensions
in older modes.

That matters because ProVeLines did not necessarily conform strictly to one
standard of its own period. It relied on the behaviour of a particular compiler
family: permissive defaults plus GNU extensions.

### GCC 5 — the default language changes

The GCC 5 porting guide announces the move from `gnu89` to `gnu11`. It also
describes the changed inline semantics and shows undeclared functions becoming
visible as warnings.

For a build script that does not specify its complete language dialect,
upgrading the compiler silently changes the language in which the program is
interpreted.

### GCC 10 — common symbols stop being common

The GCC 10 porting guide describes `-fno-common` as the new default. It
recommends one real definition plus `extern` declarations as the proper repair,
while documenting `-fcommon` as a workaround for legacy C.

That change maps directly onto LTL2BA's `rank` and `scc_stack` failure.

### GCC 14 — invented function signatures are no longer accepted

Historically, a call made before a declaration could be interpreted as a
function returning `int`. On a 64-bit architecture, that assumption is not a
cosmetic issue: the real return value might be a pointer, arguments might use
different registers or promotions, and the caller and callee might disagree on
the ABI.

GCC 14 made several such type errors fatal by default. Its porting guide
recommends making the real prototypes visible. It also documents selective
`-Wno-error=...` options as a temporary porting aid.

That change maps directly onto `SelectStream`, `PutSeed`, `yylex` and the other
undeclared calls.

### GCC 15 — empty parentheses acquire a meaning

ProVeLines declares:

```c
extern int yyparse();
```

and later calls:

```c
yyparse(&globalSymTab, &mtypes, &costFormula);
```

Through C17, empty parentheses in a declaration meant that the parameter list
was unspecified. The compiler could not verify the call properly. In C23,
`yyparse()` means the same as `yyparse(void)`: the function takes no arguments.

GCC 15 changed its default C dialect from `gnu17` to `gnu23`, so it can now state
unambiguously that the call supplies too many arguments. The language did not
invent a new bug. It removed the ambiguity that had hidden an old interface.

## An important historical nuance

It is fair to say that the old environment was more permissive, but the phrase
needs precision.

Some constructions in ProVeLines had already ceased to be valid standard C
years before the project was written. GCC continued accepting them as extensions
or warnings. The code therefore depended less on the formal standard of its era
than on the tolerance of the implementation used by its contributors.

Modern compilers are not arbitrarily making C harder. They are rejecting
situations that were always fragile:

- a function called with an unknown signature;
- a return value assumed to be `int` when it may have another representation;
- several translation units defining one external variable;
- a function declaration that does not describe its parameters;
- a generated Bison call whose arguments do not match the Flex scanner.

The stricter diagnostics prevent a particularly dangerous outcome: an
apparently successful build whose caller and callee silently disagree at
runtime.

## The environment was larger than GCC

Not every failure came from compiler evolution.

The CRLF problem came from crossing Git for Windows and Bash. The CUDD header
problem came from losing Unix symbolic-link metadata. The parser-generation
problem depends on the precise relationship between Bison, Flex, the grammar
directives and the retained generated files.

The original environment was therefore not just “an old compiler.” It included:

- Unix LF line endings;
- functional symbolic links;
- a particular GCC default dialect;
- pre-GCC-10 common-symbol behaviour;
- permissive handling of undeclared functions;
- specific Bison and Flex generation conventions;
- Makefiles and vendored library snapshots expected to live together.

None of that contract was written in one place. It was distributed across the
machine, the filesystem, compiler defaults, generated code and the memories of
the contributors.

That is why the same unchanged source can become obsolete without any algorithm
inside it becoming less valuable.

## The first binary is a bridge, not a verdict

The compatibility experiments eventually produced a real Linux executable.
Inspection identified a 64-bit x86-64 ELF containing expected symbols such as
`Cudd_Init`, `SelectStream`, `hashlittle` and `yyparse`.

Asking it for help produced the first observable response:

```bash
./provelines --help
```

```text
Error: The fPromela file does not exist or is not readable!
 --
Usage: ./provelines [options] model.pml
...
```

ProVeLines does not actually implement a dedicated `--help` option. It assumes
the final argument is a model filename, tries to open a file literally named
`--help`, then prints its usage text through the error path and exits with status
`1`.

That modestly awkward response still proves that Linux loaded the executable,
initialization ran, and control reached ProVeLines' own command-line code.

It does not prove that the parser/scanner mismatch is safe. It does not prove
that a model can be verified correctly. It does not make the compatibility
flags permanent design decisions.

The first binary restores an observation point. Nothing more — and nothing
less.

The compiler choice that crossed the final build boundary was isolated and
pushed as
[`8916cfc`](https://github.com/samilazreg-eng/provelines-plus-plus/commit/8916cfc3c2b7c6938e9d5e89075ddd9f3ac7f033):

```text
build: select the recovery C dialect
```

That was the tempting moment. We had a binary, a focused commit and a name ready
for the milestone: `v1-buildable`.

We did not create the tag.

The executable had been produced in a working tree that had already endured
several recovery attempts. Dependencies had been compiled, generated files had
survived from earlier commands, and local material could still be helping
without appearing in the commit. The binary proved that the code could run on
this machine. It did not yet prove that the repository knew how to rebuild it.

## Build recovery report

### Confirmed

- LF line endings allow Bash to parse the script.
- `-fcommon` explains and temporarily crosses the LTL2BA linker failure.
- CUDD's nine one-line files are flattened symbolic links, confirmed by its own
  setup script.
- Forwarding headers allow CUDD to expose the intended declarations portably.
- GNU99 matches the syntax used by ProVeLines while the inherited inline option
  preserves the historical linkage convention.
- The `struct timeval` failure came from a missing direct dependency on
  `<sys/time.h>`; the explicit include compiles with profiling both disabled and
  enabled.
- Eleven undeclared calls separate the legacy sources from a normal GCC 15
  build.
- A diagnostic relaxation can produce a 64-bit executable.
- The generated Bison parser passes one argument more than the Flex scanner
  declares.
- The documented GCC 5, 10, 14 and 15 transitions corroborate the observed
  failures.

### Not yet repaired

- LTL2BA still has duplicate external definitions.
- The eleven functions do not all have authoritative, visible prototypes.
- The Bison/Flex contract is still inconsistent in the historical generated
  files.
- The diagnostic binary has not verified a representative model.
- Reproducibility from a clean Git clone has not yet been demonstrated.

### Next safe corrections

1. reproduce the build from a clean clone before calling the state buildable;
2. make every required prototype explicit in its owning header;
3. add each missing standard or project include at the caller;
4. correct the redundant Bison lexical parameter in `promela.y`;
5. regenerate the parser and verify its interface against `promela.l`;
6. replace LTL2BA's common-symbol dependency with properly scoped definitions;
7. preserve each failure and its resolution as separate build evidence;
8. only then use representative models to characterise runtime behaviour.

## When the environment moves and the code stays still

The historical investigation confirms the original intuition.

ProVeLines did not suddenly stop working. Its source remained still while the C
language, GCC and their defaults continued to evolve. The original environment
accepted incomplete declarations, merged some global definitions and preserved
historical language behaviour. The build worked while relying on assumptions it
never wrote down.

Then the distance grew.

GCC changed its default C dialect several times. It stopped merging tentative
global definitions. It strengthened type checking. It promoted old warnings to
errors. The language itself removed or redefined conventions that had once left
function interfaces unspecified. Windows transport altered line endings, and
ordinary files replaced Unix links.

The codebase did not become obsolete because its algorithms necessarily lost
their value. It became obsolete because the contract between the code and its
environment disappeared.

Restoration means writing that contract down: select the language deliberately,
declare every interface, remove dependence on tolerated behaviour, preserve
filesystem intent in portable form, and document an environment that another
machine can reproduce.

The first binary is the beginning of that restoration. Compatibility options
temporarily lent the program its old world back.

The next step was not another flag and not another edit in the same warm working
tree. Before calling the state `v1-buildable`, we needed to remove the machine's
memory from the experiment.

We needed a clean clone.

---

## Historical sources

- [GCC 4.8 — language standards and the `gnu90` default](https://gcc.gnu.org/onlinedocs/gcc-4.8.0/gcc/Standards.html)
- [Porting to GCC 5 — the change to `gnu11`](https://gcc.gnu.org/gcc-5/porting_to.html)
- [Porting to GCC 10 — the `-fno-common` default](https://gcc.gnu.org/gcc-10/porting_to.html)
- [Porting to GCC 14 — implicit function declarations become errors](https://gcc.gnu.org/gcc-14/porting_to.html)
- [Porting to GCC 15 — C23 by default and empty parameter lists](https://gcc.gnu.org/gcc-15/porting_to.html)
- [WG14 N2841 — removal of function declarators without prototypes](https://www.open-std.org/jtc1/sc22/wg14/www/docs/n2841.htm)
