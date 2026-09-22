# Episode 4 — The Roads Not Taken

> `v1-buildable` starts the default engine. It does not turn every key on the dashboard.

[Episode 3](https://github.com/samilazreg-eng/provelines-plus-plus/blob/codex/v1-buildable-recovery/chapters/03-a-clean-clone-a-dirty-secret.md)
ended with a reproducible default CUDD binary. Before leaving CORA, we tried
three of the other routes advertised by its source. Each attempt started from
`v1-buildable` in a disposable directory. None changed the tagged code.

## The real-time route: a library that has not been built

Enabling the `REALTIME` line in `build.sh` adds `clockZone-dbm.c`,
`federation.c` and five UPPAAL DBM libraries to the final link. Compilation
stops first at `#include "config.h"` in `clockZone-dbm.c`. That header is not
in the tree; UPPAAL's `configure` is meant to generate it.

Running that `configure` script stopped on missing Boost headers in our WSL
environment. `gperf` and `makedepend` were absent too. More importantly, the
tag contains no built DBM archives, and our Git import is missing 49 UPPAAL
`.cpp` files present in the [upstream CORA tree](https://bitbucket.org/maxcordy/provelines-cora/commits/f36468a9f300b8461b486a8aac7d117e3ea7db0f).
The broad `*.cpp` ignore rule had filtered them during import. This route needs
its dependency rebuilt and its source tree recovered; another GCC flag cannot
conjure either one.

## CEGAR: the switch that switches nothing

Uncommenting `#define CEGAR` in `configure.h` still produces a binary. That
sounds promising until we notice that `build.sh` never compiles
`algorithms/cegar.c`, and the executable never calls `cegar()`.

Adding that file to the compile command in the disposable copy changes the
answer. CEGAR expects `stackElt.trans` and `fsmTrans_.origFeatures`, which the
current structures do not provide. It also calls exploration functions with
arguments and return values their current signatures do not have. This is not
a dormant feature waiting for its checkbox. It is code from another API shape.

## Multi-feature and Z3: two obstacles, not one

`MULTI` alone, with the default CUDD backend, fails in `execution.c`:
`accElse` is used but never declared. `ATTR` additionally defines `Z3`; with
the Z3 backend selected, compilation meets the same `accElse` failure first.
We inserted a declaration *only in the disposable copy* to look behind that
error. The build then reached the linker and failed on `-lz3`.

The repository has Z3 headers but no built Z3 library. The upstream CORA
tree has 570 Z3 `.cpp` files missing from our tagged import. So the
temporary declaration was a diagnostic shim, not a fix, and a linked binary
would still not establish correct multi-feature behaviour.

These routes make the milestone's boundary sharper: `v1-buildable` means the
default CUDD configuration builds and starts. The other advertised paths are
separate engineering work, not hidden promises inside that tag.

## Another machine in the garage

While following those missing dependencies, we found
[ProVeLines-STC](https://bitbucket.org/SamiLazregSuidi/provelines-stc/src/master/),
published in 2022. It shares much of the ProVeLines family tree but has a
different active build: `main.cpp` compiled with `g++`, ADD/CUDD selected by
default, and stochastic checking in its configuration. Its UPPAAL directory
is present, yet real-time is disabled in the build. A directory's presence
does not name the branch of research that used it.

STC's Git history begins with a 2022 source import. Retained `.svn` metadata
points to an older `FTS/fPromela` working copy, but that trace does not prove
an exact line of descent between STC and CORA. We can compare their code and
build choices; we cannot manufacture the missing ancestry.

We gave STC's build a first run in a clean, isolated copy, redirecting CUDD's
historical system-wide install into a temporary prefix. It produced a new
ProVeLines executable, but the Git archive already carried a built LTL2BA.
When we excluded tracked objects, archives and that executable, LTL2BA failed
on duplicate `rank` and `scc_stack` symbols while `build.sh` carried on. A
temporary `-fcommon` in LTL2BA's Makefile rebuilt it, after which both
LTL2BA and ProVeLines built and the latter reached its usage message. No
repository fix or STC buildability tag follows from this experiment.

That is where CORA archaeology can stop for now. One reproducible default
binary, three optional routes with honest boundaries, and another version
worth investigating on its own branch. The time machine has a sibling; we
should not paint them the same colour before opening their engines.
