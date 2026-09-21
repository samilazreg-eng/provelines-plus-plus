#include <stdio.h>
#include <stdlib.h>
#include "error.h"
#include "list.h"
#include "main.h"
#include "boolFct.h"
#include "clockZone.h"
#include "federation.h"

ptFcz createFcz(ptBoolFct features, ptClockZone zone) {
	ptFcz fcz = (ptFcz) malloc(sizeof(tFcz));
	if(!fcz) failure("[createFcz] Out of memory.\n");
	fcz->features = features;
	fcz->zone = zone;
	return fcz;
}

ptFederation createFederation(ptBoolFct features, ptClockZone zone) {
	return listAdd(NULL, createFcz(features, zone));
}

void destroyFederation(ptFederation f, byte preserve) {
	ptFederation tmp = f;
	while(tmp) {
		ptFcz fcz = (ptFcz) tmp->value;
		if(!preserve) {
			destroyBool(fcz->features);
			zoneDestroy(fcz->zone);
		}
		free(fcz);
		tmp = tmp->next;
	}
}

ptFederation copyFederation(ptFederation f, byte fullCopy) {
	ptFederation new = NULL;
	ptFederation tmp = f;
	while(tmp) {
		ptFcz value = (ptFcz) tmp->value;
		if(fullCopy)
			new = listAdd(new, createFcz(copyBool(value->features), zoneCopy(value->zone)));
		else
			new = listAdd(new, createFcz(value->features, value->zone));
		tmp = tmp->next;
	}
	return new;
}

/*
 * WARNING: Does not preserve the features and the zone.
 */
ptFederation addElement(ptFederation f, ptBoolFct features, ptClockZone zone, byte * fresh, ptBoolFct * freshProducts) {
	ptFederation tmp = f;
	byte insert = 1;
	if(fresh) *fresh = 1;
	while(tmp) {
		ptFcz elt = (ptFcz) tmp->value;
		tmp = tmp->next;
		ptFcz leftover = NULL;
		byte zoneComp = zoneCompare(zone, elt->zone);
		if(zoneComp == ZONE_EQUAL) {
			if(leftover)
				failure("[explore] Error: There is more than one HtState with the same zone in hashtable.\n");
			leftover = elt;
		}
		else if(zoneComp == ZONE_SUBSET) {
			if(!elt->features) {
				tmp = NULL;
				if(fresh) *fresh = 0;
				insert = 0;
			}
			else {
				features = addConjunction(features, negateBool(elt->features), 0, 0);
				if(!isSatisfiableWrtFD(features)) {
					tmp = NULL;
					if(fresh) *fresh = 0;
					insert = 0;
				}
			}
		}
		else if(zoneComp == ZONE_SUPSET) {
			if(!(features))
				f = listRemove(f, tmp->value);
			else {
				elt->features = addConjunction(elt->features, negateBool(features), 0, 0);
				if(!isSatisfiableWrtFD(elt->features)) {
					f = listRemove(f, tmp->value);
				}
			}
			insert = 1;
		}
		if(!tmp && leftover) {
			insert = 0;

			if(!leftover->features) {
				if(fresh) *fresh = 0;
			}
			else {
				features = addConjunction(features, negateBool(leftover->features), 0, 0);
				if(!isSatisfiableWrtFD(features)) {
					if(fresh) *fresh = 0;
				}
				else {
					leftover->features = addDisjunction(leftover->features, features, 0, 1);
				}
			}
		}
	}
	if(insert)
		f = listAdd(f,createFcz(features, zone));
	if(fresh && *fresh && freshProducts) {
		*freshProducts = features;
	}
	return f;
}

ptFederation disjunctFederation(ptFederation f1, ptFederation f2, byte preserveLeft, byte preserveRight) {
	ptFederation left;
	if(preserveLeft)
		left = copyFederation(f1, 1);
	else
		left = f1;
	ptFederation right;
	if(preserveRight)
		right = copyFederation(f2, 1);
	else
		right = f2;
	while(right) {
		ptFcz value = (ptFcz) right->value;
		left = addElement(left, value->features, value->zone, NULL, NULL);
		right = right->next;
	}
	listDestroy(right);
	return left;
}

byte equalsFederation(ptFederation f1, ptFederation f2) {
	if(listCount(f1) != listCount(f2))
		return false;
	ptList left = f1;
	while(left) {
		ptFcz leftValue = (ptFcz) left->value;
		ptList right = f2;
		byte found = false;
		while(right && !found) {
			ptFcz rightValue = (ptFcz) right->value;
			byte zoneComp = zoneCompare(leftValue->zone, rightValue->zone);
			if(zoneComp == ZONE_EQUAL) {
				if(equalsWrtFD(leftValue->features, rightValue->features))
					found = true;
				else // the two federations are not equal.
					return false;
			}
			right = right->next;
		}
		if(!found)
			return false;
		left = left->next;
	}
	return true;
}
