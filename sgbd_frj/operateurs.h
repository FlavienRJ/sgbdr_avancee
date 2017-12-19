/*
 * OPERATEURS SGBD
 */

#ifndef operateurs_h
#define operateurs_h

#include <stdio.h>
#include "sgbd.h"
#include "nuplet_helper.h"

RELATION newRELATION(int attsize, int maxsize);
RELATION OpUnion(RELATION r1, RELATION r2);
RELATION OpInter(RELATION r1, RELATION r2);
RELATION OpRestrictionCST(RELATION r1, int att, int operateur, int valeur); // operateur : 0 : == ; 1 : < ; 2 : >
RELATION OpRestrictionATT(RELATION r1, int att1, int operateur, int att2);  // idem ici
RELATION OpProjection(RELATION r1, int* attributs, int taille);
RELATION OpProduitCartesien(RELATION r1, RELATION r2);
RELATION OpJointure(RELATION r1, RELATION r2, int attr1, int attr2);

#endif
