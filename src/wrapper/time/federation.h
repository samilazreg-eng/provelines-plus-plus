/*
 * A federation is a union of featured clock zone, that is, a set of couples (f,z) where f is a feature expression and z is a clock zone. A federation therefore associates a product with a (possibly empty) union of clock zones.
 */

struct fcz_ {
	ptBoolFct features;
	ptClockZone zone;
};
typedef struct fcz_ tFcz;
typedef struct fcz_ * ptFcz;

typedef ptList ptFederation;

ptFederation createFederation(ptBoolFct features, ptClockZone zone); // Returns the federation (features, zones).
void destroyFederation(ptFederation f, byte preserve); // Destroys the federation 'f'. Iff preserve is 0, all the contained feature expressions and zones are destroyed as well.
ptFederation addElement(ptFederation f, ptBoolFct features, ptClockZone zone, byte * fresh, ptBoolFct * freshProducts); //
ptFederation disjunctFederation(ptFederation f1, ptFederation f2, byte preserveLeft, byte preserveRight); // Returns the union of federations 'f1' and 'f2'. Iff preserveLeft (resp. preserveRight) is 0 then f1 (rsp. f2) is destroyed in the process.
ptFederation copyFederation(ptFederation f, byte fullCopy); // Returns a copy of 'f'. If fullCopy is 1 then the clock zones and feature expressions are copied as well (otherwise only their reference are copied).
byte equalsFederation(ptFederation f1, ptFederation f2); // Returns 1 if the federations are equal, 0 otherwise.
