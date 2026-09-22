# Episode 6 — CORA Keeps Its Own Time

> No UPPAAL clock, no TCTL checker: this experiment uses CORA's own `time`.

After recovering the dependency sources, we tried a small timed product
family. The interesting result did not require the DBM libraries or a
`clock` declaration. CORA already stores elapsed `time` in an exploration
state. Its `wait(expr)` supplies a numeric delay, and its supported
`check F ... within N` query tests a bound on that accumulated time.
The checking code compares `state->time <= property->within`; the endpoint
is included.

Our first model blurred that distinction. `wait(c > 1)` looks like a clock
guard, but the expression is evaluated as a delay. With `c` initially zero,
it advances no time. Replacing it with `wait(1)` made the intended unit
of elapsed time visible. `wait(5)` supplied the slower branch. A default
CORA build can run the same numeric-delay experiment: the result is not
evidence that a real-time DBM path works.

## One optional feature, two arrival times

The feature model makes `Formal` optional. In a deliberately tiny probe,
`Formal` reaches `done` after one time unit and `!Formal` after five.
`check F done == 1 within 2` reported only the `Formal` product. We used
`within 2` for this integer-time probe because `within 3` also admits a
state reached at exactly time three; it does not express a strict `< 3`
boundary. Nor is this query a universal TCTL property. It asks whether
`done` is reachable within CORA's bound for each product.

The TVL file is optional at the CLI: without a matching basename, CORA
continues without a feature model. An explicit `-fm` exposes a load failure.
The bundled TVL parser's `java -jar` entry point failed on our current JVM
because it could not find SAT4J; invoking its main class with the bundled
SAT4J jars on the classpath generated DIMACS data that `-fmdimacs` accepted.
That gave us a real two-product family, rather than just toggling a Boolean
by hand.

One loose thread remains: replacing the explicit `!Formal` guard with
`else` unexpectedly changed the family verdict. We should characterise
that before using `else` in a teaching example. The next step is to turn
this probe into a reproducible small test and pin down what CORA's `time`
means across more than one transition. The time machine was already ticking;
we had been staring at the wrong dashboard.
