# Episode 6 — The Clock and the Fossil Parser

> The model asks a timed question. The executable we have today cannot yet
> understand it.

Our target is a clocked model with an optional `Formal` feature: its two
branches use bounds of one and five in a `while (...) wait` construct, and
we want to ask whether `done` can be reached within two. The intended
property is `E F (<= 2) (done == 1)`. We have not yet established the exact
semantics of that historical wait construct. The proposed model also declares
`clock c` without naming it in either branch, so we should not assume which
constraint that declaration contributes.
This is a CLOCK/TCTL experiment, not a test of CORA's separate accumulated
`time` and `check F ... within N` feature. Those two routes must not be
presented as interchangeable.

The first obstacle is hiding in plain sight. `build.sh` compiles
`parser/y.tab.c`, generated from the active `parser/promela.y`. That grammar
accepts `wait(expr) then statement` and CORA's `check F ... within N`, but
has no production for the clocked `while (...) wait` statement or the
`E F (<= 2)` property. Merely compiling with `CLOCK` does not restore
grammar rules that are absent from its source.

There is another generated parser in the tree, `parser/promela.tab.c`. It
contains actions for clock registration, a time-invariant statement, and
TCTL formulas. It is a useful archaeological clue, not a drop-in fix:
`build.sh` does not compile it, its corresponding grammar source is not the
active one, and its TCTL actions call `createTctlFormula` with a different
signature from `logic/tctl.h`. Some generated actions are syntactically
broken too. Even getting that parser to compile would be only the first
step; `main.c` currently treats the parsed property as a CORA cost formula
and passes it to the ordinary exploration checker. It has no path that
dispatches a TCTL formula to a TCTL checking algorithm.

We did build a `CLOCK`-flavoured executable in a disposable WSL copy after
recovering dependency sources and building UPPAAL's DBM libraries. It
accepted a clock declaration after a small parser change. That establishes
a build foothold, **not** the semantics of the proposed model or property.
The earlier numeric-delay probes do not answer the clocked question.

The next movement is therefore concrete: recover the intended grammar,
wire clock declarations and timed statements to the zone representation,
then trace a bounded `E F` formula from parsing through an actual checking
algorithm. Only after the one-unit and five-unit products produce distinct
clocked results can we call this route working. For now, the garage contains
the parts and an old dashboard. We still need to connect the engine.

## First reanimation

We have now restored the historical `spec E F (<= N) ...` and
`while (expr) wait` productions to the active parser. A CLOCK build parses
the literal `while (c < 5) wait` probe with the optional `Formal` TVL model,
then stops explicitly: the zone-based checker is not connected. The default
CORA build still compiles. This is a parser milestone, not a TCTL verdict.

The old execution code also makes the wording important: `while (c < 5)
wait` is an invariant on a location, not an instruction to sleep for five
units. It does not by itself force the following assignment to happen at
time five. That semantic question is our next test once the zone state and
transitions are restored.
