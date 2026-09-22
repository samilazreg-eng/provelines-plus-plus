# Episode 1 — Archaeology Begins

> I only wanted to build it.

The first objective sounded deliberately modest:

> Take the local snapshot believed to preserve ProVeLines, follow its own
> instructions, and observe the first honest build.

No refactoring. No migration plan. No opportunistic cleanup. Before deciding
what this software ought to become, we first needed to see what it actually was.

The historical README said Linux or macOS. The source was available under WSL.
There was a build script. This looked less like archaeology than administration.

```bash
cd src
./build.sh
```

The time machine did not start.

```text
./build.sh: line 1: $'clear\r': command not found
./build.sh: line 2: $'clear\r': command not found
./build.sh: line 3: $'\r': command not found
./build.sh: line 4: cd: $'./parser/\r': No such file or directory
./build.sh: line 12: syntax error near unexpected token `fi'
./build.sh: line 12: `fi;'
```

At first glance, `clear` appeared to be the problem. It was not.

The important character in the error was the one we could barely see: `\r`.

## The first artefact was invisible

The script in our local baseline candidate used Windows CRLF line endings. Bash
expects Unix LF line endings, so it interpreted the carriage return as part of
every command. It was not trying to execute `clear`; it was trying to execute a
command named `clear\r`. It was not trying to enter `./parser/`; it was looking
for a directory whose name ended in an invisible carriage return.

This was not yet a C problem, a compiler problem, or even a build-system
problem. We had failed before compiling a single line of ProVeLines.

That small failure was already useful evidence. Our copy had crossed
operating-system boundaries, but the build script had not crossed them intact.
We did not yet know whether the carriage returns came from the historical
project or from our preservation path. “Legacy” was not permission to blame the
original authors for every strange byte in front of us.

For the purpose of the investigation, the script was normalized locally to LF.
This was not accepted as the modern build solution. It was only the smallest
reversible intervention that allowed the historical build to reveal its next
assumption.

The durable checkout fix was later isolated in
[`c442a06`](https://github.com/samilazreg-eng/provelines-plus-plus/commit/c442a06001cbfdf8fcd9da31592c12149d69ff2f):
an LF policy for shell entry points, with no change to the historical build
commands themselves.

Then we tried again.

## This time, it really did start

Or, more accurately, it began attempting everything.

MiniSat reached the modern C++ compiler and failed. The script did not stop.
LTL2BA reached the linker and failed. The script still did not stop. CUDD built
archive after archive, and the final ProVeLines command exposed another wall of
C diagnostics. What had looked like a small academic C program was assembling a
private ecosystem with no interest in failing fast.

The first visible obstruction had been removed only to reveal several more,
spread across third-party libraries, generated files and ProVeLines itself. One
run produced many failures, but their order mattered: the last diagnostic was
not the first broken prerequisite.

That was the point where the investigation deliberately changed scale. Reading
the errors one at a time would explain individual symptoms, but first we needed
to understand the system producing them. Why was a relatively small academic
tool compiling so much code? Which parts belonged to ProVeLines? Which parts
were copied dependencies, generated artefacts or abandoned experiments? And
could Git even reproduce the tree we were looking at?

The detailed build investigation would become the subject of the next episode.
This one would establish the terrain.

## How large is this thing?

While the dependencies were compiling, a simple measurement provided the next
plot twist:

```bash
cloc .
```

```text
2499 files
681,997 lines of code
```

Wait.

**681,997 lines?**

The language breakdown looked less like one C model checker and more like a
small archaeological site:

```text
C++             271,664
C               168,937
C/C++ headers   119,553
HTML             46,912
Bourne Shell     36,759
...
```

The obvious but wrong conclusion would have been that ProVeLines itself was a
682,000-line system. So the next analysis established boundaries instead of
producing a more impressive number.

| Investigated boundary | Lines of code | Share of the local tree |
| --- | ---: | ---: |
| Embedded libraries under `src/lib` | 662,316 | 97.10% |
| Hand-written ProVeLines code | 11,537 | 1.69% |
| Generated Flex/Bison parser code | 8,079 | 1.18% |
| Build, configuration and remaining material | 188 | 0.03% |

The total moved slightly while the investigation documents were being written,
but the proportions did not. The discovery was stable:

> ProVeLines is not a 682,000-line program. It is a roughly 11,500-line program
> travelling with more than 660,000 lines of dependencies, generators,
> documentation and old tooling.

The build had seemed large because it *was* large. The product was small; its
luggage was not.

## Reconstructing the machine

The dependency directories were not a random collection. Together they exposed
the architecture and the research questions that had shaped the program.

```text
Promela model
    |
    +-- C preprocessor (`cpp`)
    |
    +-- Flex/Bison parser
    |
    +-- LTL formula -- LTL2BA --> never claim
    |
    +-- TVL feature model -- Java parser --> DIMACS clauses
    |                                      |
    |                                      +-- CUDD BDD backend
    |                                      +-- MiniSat alternative
    |                                      +-- Z3 alternative
    |
    +-- state exploration
           +-- Clark hashtable
           +-- Jenkins lookup3
           +-- RNGS
           +-- Judy alternative
           +-- UPPAAL DBM optional real-time support
```

This graph also showed that “dependency” meant several different things in one
script:

- CUDD was built and linked statically into the default binary.
- Clark Hashtable and RNGS were compiled directly from vendored C sources.
- Jenkins' `lookup3.c` was included textually by a ProVeLines source file.
- LTL2BA was built as a separate executable and launched later with `system()`.
- TVLParser was already packaged as a JAR and launched through Java.
- MiniSat was built on every run even though the default configuration selected
  CUDD and did not link MiniSat.
- Z3, Judy and UPPAAL DBM represented alternative or optional configurations.
- STP occupied more than 115,000 lines but was not referenced by the active
  build at all.

The build script was therefore doing at least four jobs: dependency builder,
configuration interface, linker command and runtime assembly guide. Its
commented lines were also the closest thing the project had to a feature model
for its own build.

## A twenty-eight-year time span in one directory

The libraries carried their own dates. Read together, they formed a compressed
history of formal-methods tooling from the late 1990s through the 2010s.

| Component | Version or dated evidence in the tree | Approximate age in 2026 | Role in the default path |
| --- | --- | ---: | --- |
| RNGS | revision dated 22 September 1998 | 28 years | compiled directly |
| Clark Hashtable | sources dated 2002–2004 | 22–24 years | active |
| Jenkins lookup3 | May 2006 | 20 years | active |
| UPPAAL DBM | DBM 2.0.8; source history mainly 2003–2006 | at least 20 years | optional real-time path |
| Judy | 1.0.5, May 2007 | 19 years | inactive alternative |
| LTL2BA | 1.1, August 2007 | 19 years | built and invoked externally |
| CUDD | 2.4.2; revisions through March 2009 | about 17 years | active BDD backend |
| STP | SVN revision 446; Windows port dated December 2009 | about 16–17 years | dormant |
| MiniSat | 2.2 generation; files dated through 2010 | about 16 years | built but not linked by default |
| TVL Parser | internal sources from 2010; JAR assembled in 2017 | 9–16 years | invoked through Java |
| Z3 | 4.3.1, from the 2012–2013 generation | about 13–14 years | inactive alternative |

The versions explained more than age. They explained relationships.

The program could translate temporal logic through LTL2BA, represent feature
constraints through CUDD, experiment with SAT through MiniSat, leave a path
toward SMT through Z3, and optionally attach timed-state machinery from UPPAAL.
Judy and Clark represented competing state-storage strategies. Jenkins supplied
the hash function. RNGS supplied multiple random streams.

This was not dependency management in the contemporary package-manager sense.
It was a preserved research workstation.

## What the repository says about its contributors

Source code cannot tell us everything about the people who wrote it, and an
archaeological report should not turn inference into biography. Still, the
technical evidence does reveal a working culture.

The project appears to have optimized for experimentation and local
self-sufficiency:

- dependencies were copied into the source tree instead of resolved from a
  system package manifest;
- parser outputs were retained so the program could sometimes build without
  Flex and Bison;
- alternative algorithms were selected by editing shell variables and
  commenting or uncommenting source lists;
- external tools communicated through temporary files and `system()` calls;
- the build favored a known laboratory environment over an independently
  reproducible repository state;
- optional research paths accumulated beside the active configuration instead
  of being removed when an experiment ended.

In that context, vendoring was not necessarily careless. It reduced reliance
on whatever package versions happened to be installed on another academic
machine. Keeping generated files made a build possible when parser generators
were missing. Copying a solver snapshot froze an experimental dependency at a
known point in time.

Those choices solved real problems for their original contributors.

They also transferred responsibility to the future. Once the original machine
and its unwritten conventions disappeared, the repository had to explain
decisions that had previously lived in its environment.

Then the upstream archive supplied the missing control sample.

## The same commit arrived in two different costumes

We downloaded the Bitbucket archive for commit `f36468a9f300`, extracted it
directly under Linux and inspected it before building. The comparison changed
the attribution of several failures.

The upstream `src/build.sh` already used Unix LF endings. The nine entries under
`src/lib/cudd/include` were real symbolic links, including:

```text
cudd.h    -> ../cudd/cudd.h
cuddInt.h -> ../cudd/cuddInt.h
util.h    -> ../util/util.h
```

Our local baseline candidate had converted the script to CRLF and flattened
those links into ordinary files containing only their target paths. The old
project had not authored a header whose C syntax was `../util/util.h`. A later
transport step had taken valid filesystem metadata and turned it into invalid C.

This distinction matters. The CRLF failure and flattened CUDD headers are real
ProVeLines++ recovery problems, but they are not original ProVeLines design
decisions. They belong to the provenance of our starting artefact.

The control sample also prevented an easy archaeological mistake: inspecting
one damaged copy and confidently explaining why the past was broken. Before
diagnosing legacy code, identify which parts are legacy and which parts arrived
last Tuesday wearing an old coat.

Git then supplied the next piece of evidence.

## Our import remembered less than its source directory

The complete local tree contained 682,120 lines when the forensic recount was
performed. But counting only files actually tracked by Git produced a very
different result:

| Repository view | Lines of code |
| --- | ---: |
| Files tracked by Git | 401,990 |
| Ignored files present in the checkout | 280,007 |
| Untracked Markdown added during the investigation | 123 |
| Complete local tree at measurement time | 682,120 |

More than forty-one percent of the code visible to `cloc .` was ignored by our
new Git history.

The ignore rules explained why:

```gitignore
*ltl2ba
*.cpp
*.txt
```

The `*.cpp` rule hid hundreds of C++ sources belonging to Z3, STP and UPPAAL
DBM. More seriously, `*ltl2ba` matched the entire `src/lib/ltl2ba` directory.

That directory was not incidental. The build script entered it and ran `make`.
The application later invoked its executable to translate LTL formulae. Yet our
import commit tracked zero files beneath it.

The Bitbucket repository did contain the LTL2BA files. Git ignore rules do not
remove files already tracked in their original history. The loss occurred when
the source tree was copied into a new repository and added again: the old ignore
patterns were re-applied to files that no longer had tracked status.

The current working tree could proceed because the ignored files still existed
locally. A fresh clone of *our import* could not reproduce that state from its
new history alone. The source had survived; our baseline commit had not recorded
all of it.

This changed the meaning of the initial build attempt. We had not proved that
the repository could build. We had proved that this particular checkout,
carrying ignored historical material, could get far enough to expose the next
layer of failures.

The local directory was not merely a checkout. It was an artefact, and the
import procedure was now part of its provenance.

## Archaeology report

By the end of the first investigation, the evidence supported the following
findings.

### Finding 1 — The first failure belonged to our transport path

CRLF endings prevented Bash from parsing the historical script. Removing the
carriage returns exposed the build; removing `clear` alone would only have
hidden two symptoms. The upstream archive retained LF, so this was damage to our
baseline candidate rather than an authored build assumption.

### Finding 2 — The apparent system size is dominated by dependencies

Approximately 97% of the local source count lies under `src/lib`. The
hand-written ProVeLines surface is roughly 11,500 lines.

### Finding 3 — The build does more work than the default binary requires

MiniSat is built but not linked by the selected CUDD configuration. Several much
larger solver and real-time trees are inactive or dormant. Build duration is not
a reliable proxy for product size.

### Finding 4 — Our baseline import is not yet self-reproducing

About 280,000 lines present locally are ignored by Git. The entire LTL2BA source
tree is among them even though the historical build requires it. Those sources
exist upstream; our new history omitted them when it re-applied the inherited
ignore rules.

### Finding 5 — Filesystem metadata is source provenance

The Bitbucket archive preserved CUDD's symbolic links. Their flattened form in
our local snapshot was introduced later and must not be misreported as an
original CUDD header defect.

### Finding 6 — The dependency tree preserves the project's research history

The repository spans components dated from 1998 to 2017 and records successive
experiments in BDDs, SAT, SMT, timed systems, feature models and state-storage
strategies. What looks like clutter is also provenance.

## We did not start the engine

At the beginning, the mission was to produce a binary.

By the end, we knew that this was not yet the right success criterion. A binary
produced from one historically contaminated working tree would be interesting,
but it would not establish a reproducible build. Making one command quieter
would not explain the rest of the build. Deleting unused-looking libraries
might make the repository smaller, but it could erase the record of
configurations we had not yet understood.

So Episode 1 ends before the victory lap.

No `provelines --help`. No claim that the recovered executable behaves
correctly. No modern build system introduced while the old one is still being
mapped.

We came looking for one compilation error and found a chain of environments:
Windows line endings introduced into our copy, Unix shell assumptions,
filesystem metadata lost in transit, generated parsers, statically linked C
libraries, Java subprocesses, optional solvers, inherited ignore rules and a
working tree carrying files absent from its new Git history.

The failure was no longer mysterious.

For the first time, the repository was beginning to make sense.

The next episode can bring the build back to the future. This one only
establishes what must be brought back.
