# Episode 3 — A Clean Clone, a Dirty Secret

> The first binary ran. The repository had not yet proved it could make another.

[Episode 2](https://github.com/samilazreg-eng/provelines-plus-plus/blob/chapter-2/chapters/02-back-to-the-future.md)
ended with a working local executable and an unclaimed tag: `v1-buildable`.
Before using that name, we cloned the candidate into a fresh directory and
asked the repository to repeat the trick.

## I. The clean clone fights back

We already knew something odd about LTL2BA: its source directory was present
in the upstream archive and in our working tree, but absent from our first Git
import. The rule `*ltl2ba` in `.gitignore` looked suspicious. We removed it,
restored the dependency, added `-fcommon` to its Makefile, and gathered the
recovery work in
[`a4891d4`](https://github.com/samilazreg-eng/provelines-plus-plus/commit/a4891d4270e89bafd3bdf6780352e8d6015518d5)
on `buildable/candidate`.

This was a commit-shaped experiment, not a release. Unfortunately, removing
the ignore rule also admitted the already-built `ltl2ba` executable. The clone
reported:

```text
make: 'ltl2ba' is up to date.
```

We had transported the answer along with the question. That build did not
exercise `-fcommon` at all. A later reconstruction from sources in a disposable
directory did: `-fcommon` linked LTL2BA; `-fno-common` failed on the duplicate
`rank` and `scc_stack` symbols.

The rest of the clone was less discreet. MiniSat failed on its old `mkLit`
friend declaration, and the script continued. CUDD then could not find
`cuddSymmetry.c`. Its `nanotrav` directory was also missing. CUDD's Makefile
ran `cd nanotrav` inside a subshell, did not stop when that failed, and ran
`make` from the parent CUDD directory instead. The parent started the same
loop again. By `make[136]`, we interrupted it. No `provelines` binary had
appeared.

The missing names pointed back to `.gitignore`:

```gitignore
*ltl2ba
*nanotrav
*dSym*
```

The last pattern matched both `cuddSymmetry.c` and `cuddZddSymm.c`. Other
rules, including `*.cpp` and `*.txt`, had hidden sources and build files from
optional dependencies. The clean clone had found more than a broken compiler
flag: it had found an incomplete repository.

At this point we checked the provenance. Bitbucket's upstream repository is
itself Git, at commit
[`f36468a9f300`](https://bitbucket.org/maxcordy/provelines-cora/commits/f36468a9f300b8461b486a8aac7d117e3ea7db0f).
Its tracked tree contains those files despite its broad ignore rules. The
damage happened when we downloaded a source archive, lost the old Git index,
and added the files to a new repository. Rules that had not affected already
tracked upstream files became filters for every newly added file. The ZIP did
not contain `.git`; source archives normally do not.

We had created the clone to validate the build. Instead, it corrected our
understanding of what the repository contained.

## II. Give the repository its memory back

We fetched the upstream Git commit and compared its tracked tree with our
candidate. There were 805 upstream-only paths, including 38 under CUDD. We
restored those 38 CUDD files byte-for-byte in
[`35b0720`](https://github.com/samilazreg-eng/provelines-plus-plus/commit/35b0720),
including the two symmetry sources and the complete `nanotrav` directory.
The same commit narrowed the executable ignore rules and removed the
precompiled LTL2BA binary. A clean build now had to create that executable
itself.

Our first build-script revision,
[`07904fa`](https://github.com/samilazreg-eng/provelines-plus-plus/commit/07904fa),
stopped on errors and built only the selected CUDD path. It produced a fresh
ProVeLines ELF. But it also skipped MiniSat and `nanotrav`, closing off build
paths we meant to investigate later. We had made the default route work by
moving the other signposts.

So we tried the complete historical dependency sequence. Once CUDD's missing
files were back, its full build, including `nanotrav`, passed. A small MiniSat
source correction also made its library build, recorded in
[`6105c8b`](https://github.com/samilazreg-eng/provelines-plus-plus/commit/6105c8b),
and [`f7d69b3`](https://github.com/samilazreg-eng/provelines-plus-plus/commit/f7d69b3)
restored every dependency step in `build.sh`.

Then we reconsidered MiniSat. The default ProVeLines binary uses CUDD; the
historical script had continued after MiniSat's error, and its library was not
linked into that binary. Repairing MiniSat was premature for this milestone.
The final correction,
[`df007d3`](https://github.com/samilazreg-eng/provelines-plus-plus/commit/df007d3),
returned its source to the upstream form. The script still attempts MiniSat
and reports its failure, while required LTL2BA, CUDD and ProVeLines steps stop
on error.

From an archive of that exact final Git commit, with no inherited object files
or prebuilt executables, `bash ./build.sh` exited successfully. It rebuilt
LTL2BA, built CUDD and `nanotrav`, produced a new 64-bit Linux `provelines`,
and reached the program's own usage message. MiniSat's failure remained visible
in the log. That is the state marked by `v1-buildable`.

The tag makes a narrow promise: the historical default CUDD configuration can
produce and launch a binary in the reference WSL2 Ubuntu environment with
GCC/G++ 15.2. It does not certify the MiniSat backend, the other optional
libraries, or the verifier's behaviour on a model. The temporary
`-Wno-error=implicit-function-declaration` flag, missing prototypes and the
parser/scanner disagreement still deserve their own work.

The clone was a better reviewer than our warm working tree. It could not be
charmed by yesterday's object files, and it had no memory of the files we had
forgotten to commit. That is why the tag finally means something.
