#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>
#include <string.h>
#include "error.h"
#include "list.h"
#include "main.h"
#include "config.h"
#include "base/inttypes.h"
#include "base/intutils.h"
#include "hash/compute.h"
#include "base/relation.h"
#include "dbm/constraints.h"
#include "dbm/print.h"
#include "dbm/dbm.h"
#include "clockZone.h"

static int _dim = 0;
ptLList _enClocks;

void initDimension(int dim) {
	_dim = dim;
}

ptClockZone initClockZone() {
	if(_dim == 0) failure("[initClockZone] Clock dimension cannot be zero.\n");
	raw_t * dbm = malloc(_dim*_dim*sizeof(raw_t));
	dbm_init(dbm, _dim);
	return dbm;
}

ptClockZone zoneIntersect(ptClockZone z1, ptClockZone z2, byte preserve) {
#ifdef DEBUGZONE
	printf("[zoneIntersect]\n");
	printZone(z1);
	printZone(z2);
#endif
	ptClockZone working;
	if(preserve) working = zoneCopy(z1);
	else working = z1;

	if(zoneEmpty(working)) return working;
	if(zoneEmpty(z2)) return zoneCopy(z2);

	dbm_intersection((raw_t *) working, (raw_t *) z2, _dim);
#ifdef DEBUGZONE
	printZone(working);
	printf("[/zoneIntersect]\n");
#endif
	return working;
}

ptClockZone zoneReset(ptClockZone z, char * c, byte preserve) {
#ifdef DEBUGZONE
	printf("[zoneReset]\n");
	printZone(z);
#endif
	ptClockZone working;
	if(preserve) working = zoneCopy(z);
	else working = z;
	int * x = (int *) (llistFind(_enClocks, c))->value;
	if(!x) failure("[zoneConstraint] Unknown clock '%s'.\n", c);
	dbm_updateValue((raw_t *) working, _dim, *x, 0);
#ifdef DEBUGZONE
	printZone(working);
	printf("[/zoneReset]\n");
#endif
	return working;
}

ptClockZone zoneResetAll(ptClockZone z) {
	ptClockZone working;
	int i;
	for(i = 1; i < _dim; i++) {
		dbm_updateValue((raw_t *) z, _dim, i, 0);
	}
	return z;
}

ptClockZone zoneFuture(ptClockZone z, byte preserve) {
#ifdef DEBUGZONE
	printf("[zoneDelay]\n");
	printZone(z);
#endif
	ptClockZone working;
	if(preserve) working = zoneCopy(z);
	else working = z;

	if(zoneEmpty(working)) return working;

	dbm_up((raw_t *) working, _dim);
#ifdef DEBUGZONE
	printZone(working);
	printf("[/zoneDelay]\n");
#endif
	return working;
}

ptClockZone zonePast(ptClockZone z, byte preserve) {
#ifdef DEBUGZONE
	printf("[zoneDelay]\n");
	printZone(z);
#endif
	ptClockZone working;
	if(preserve) working = zoneCopy(z);
	else working = z;

	if(zoneEmpty(working)) return working;

	dbm_down((raw_t *) working, _dim);
#ifdef DEBUGZONE
	printZone(working);
	printf("[/zoneDelay]\n");
#endif
	return working;
}

// x - y <= (<) bound
ptClockZone zoneConstraint(ptClockZone z, char * c1, char * c2, int bound, byte strict, byte preserve) {
#ifdef DEBUGZONE
	printf("[zoneConstraint]\n");
	printZone(z);
#endif
	ptClockZone working;
	if(preserve) working = zoneCopy(z);
	else working = z;

	if(zoneEmpty(working)) return working;

	strictness_t strictness;
	if(strict) strictness = dbm_STRICT;
	else strictness = dbm_WEAK;
	raw_t constraint = dbm_bound2raw(bound, strictness);

	int * x;
	if(!c1) {
		int zero = 0;
		x = &zero;
	}
	else {
		ptLList lx = llistFind(_enClocks, c1);
		if(!lx) failure("[zoneConstraint] Unknown clock '%s'.\n", c1);
		x = (int *) (lx)->value;
	}

	int * y;
	if(!c2) {
		int zero = 0;
		y = &zero;
	}
	else {
		ptLList ly = llistFind(_enClocks, c2);
		if(!ly) failure("[zoneConstraint] Unknown clock '%s'.\n", c2);
		y = (int *) (llistFind(_enClocks, c2))->value;
	}
	dbm_constrain1(working, _dim, *x, *y, constraint);
#ifdef DEBUGZONE
	printZone(working);
	printf("[/zoneConstraint]\n");
#endif
	return working;
}

void zoneDestroy(ptClockZone z) {
	free((raw_t *) z);
}

ptClockZone zoneCopy(ptClockZone z) {
	raw_t * zcopy = malloc(_dim*_dim*sizeof(raw_t));
	dbm_copy(zcopy, (raw_t *) z, _dim);
	return zcopy;
}

byte zoneEmpty(ptClockZone z) {
	return dbm_isEmpty(z, _dim);
}

void printZone(ptClockZone z) {
	dbm_print(stdout, z, _dim);
}



byte zoneCompare(ptClockZone z1, ptClockZone z2) {
#ifdef DEBUGZONE
	printf("[zoneCompare]\n");
	printZone(z1);
	printZone(z2);
#endif

	if(zoneEmpty(z1) && zoneEmpty(z2)) return ZONE_EQUAL;
	if(zoneEmpty(z1) && !zoneEmpty(z2)) return ZONE_SUBSET;
	if(!zoneEmpty(z1) && zoneEmpty(z2)) return ZONE_SUPSET;

	byte result;
	relation_t rel = dbm_relation(z1, z2, _dim);
	switch(rel) {
		case(base_DIFFERENT): result = ZONE_INCOMPARABLE; break;
		case(base_SUBSET): result = ZONE_SUBSET; break;
		case(base_EQUAL): result = ZONE_EQUAL; break;
		case(base_SUPERSET): result = ZONE_SUPSET; break;
		default: failure("[zoneCompare] dbm_relation function gave an unexpected result.\n");
	}
#ifdef DEBUGZONE
	printf("[zoneCompare]\n");
#endif
	return result;
}

void encodeClocks(ptList clocks) {
	if(!_enClocks)
		_enClocks = list2llist(clocks);
	else
		_enClocks = list2llistConcat(_enClocks, clocks);
	int dim = llistCount(_enClocks)+1; // One for zero
	initDimension(dim);
	listDestroy(clocks);
}
