#define CTL_EF			0
#define CTL_EG			1
#define	CTL_AF			2
#define CTL_AG			3
#define CTL_AGEF		4

struct _tctlFormula {
	byte type;
	int bound;
	ptClockZone zone;
	void * premisse;
	void * property;
};
typedef struct _tctlFormula tTctlFormula;
typedef struct _tctlFormula * ptTctlFormula;

ptTctlFormula createTctlFormula(byte type, void * premisse, int bound, void * property);
void destroyTctlFormula(ptTctlFormula formula);
