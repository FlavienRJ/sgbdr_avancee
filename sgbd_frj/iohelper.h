/*
 * INPUT/OUTPUT HELPER
 * GESTION DES FICHIERS
 */


#ifndef iohelper_h
#define iohelper_h

#include <stdio.h>
#include <stdlib.h>

#include "sgbd.h"

BDD* newBDD(void);
void openBDD(char* parPath, BDD* parBdd);
void store(BDD* parBdd, int parPos, NUPLET parVal);
NUPLET get(BDD parBdd, int parPos);
int size(BDD parBdd);

#endif /* iohelper_h */

