#define ZONE_INCOMPARABLE	0
#define ZONE_SUBSET			1
#define ZONE_EQUAL			2
#define ZONE_SUPSET			3
#define GLOBAL_CLOCK	"global_clock"


typedef void * ptClockZone;
typedef int _clock;

ptClockZone initClockZone(); // Returns an unconstrained clock zone
ptClockZone zoneIntersect(ptClockZone z1, ptClockZone z2, byte preserve); // Returns the intersection of 'z1' and 'z2'. z1 is left untouched iff preserve is 1. z2 is always left untouched.
ptClockZone zoneReset(ptClockZone z, char * c, byte preserve); // Returns the clock zone obtained by resetting the value of clock 'c' to 0 in 'z'. 'z' is left untouched iff preserve is 1.
ptClockZone zoneResetAll(ptClockZone z); // Returns the clock zone obtained by resetting all clocks in 'z'.
ptClockZone zoneFuture(ptClockZone z, byte preserve); // Returns the clock zone representing the time successors of 'z'. 'z' is left untouched iff preserve is 1.
ptClockZone zonePast(ptClockZone z, byte preserve); // Returns the clock zone representing the time predecessors of 'z'. 'z' is left untouched iff preserve is 1.

/*
 * Returns the clock zone obtained by adding the constraints c1 - c2 < bound (resp. c1 - c2 =< bound) to 'z' if strict is 1 (resp. strict is 0).
 *    - 'z' is left untouched iff preserve is 1.
 *    - If c1 (resp. c2) is NULL, it is considered as zero.
 */
ptClockZone zoneConstraint(ptClockZone z, char * c1, char * c2, int bound, byte strict, byte preserve);


byte zoneEmpty(ptClockZone z); // Returns 1 if 'z' is empty, 0 otherwise.
void zoneDestroy(ptClockZone z); // Destroys 'z'.
ptClockZone zoneCopy(ptClockZone z); // Returns a copy of 'z'.
void printZone(ptClockZone z); // Prints 'z'.

/*
 * Returns:
 *    - ZONE_SUBSET (1) if 'z1' is included in 'z2';
 *    - ZONE_EQUAL (2) if 'z1' is equal to 'z2';
 *    - ZONE_SUPSET (3) if 'z2' is included in 'z1';
 *    - ZONE_INCOMPARABLE (0) otherwise.
 */
byte zoneCompare(ptClockZone z1, ptClockZone z2);


void encodeClocks(ptList clocks); // Registers a list of clock. The type of the elements of the input list must be char *. The list is destroyed afterwards.
