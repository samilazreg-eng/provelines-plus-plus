// Uncomment to enable CEGAR based verification
//#define CEGAR

// Uncomment the following line to check real-time systems.
//#define CLOCK

// Uncomment the following line to enable multi-features.
//#define MULTI

// Uncomment the following line to enable numeric features.
//#define ATTR

// At the moment, Z3 is the only SMT solver linked to ProVeLines.
// Do *NOT* uncomment the following lines.
#ifdef ATTR
	#define Z3
#endif
