/*
 * INPUT/OUTPUT HELPER
 * GESTION DES FICHIERS
 */


#ifndef iohelper_h
#define iohelper_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sgbd.h"
#include "nuplet_helper.h"

BDD* newBDD(void);
int openBDD(char* parPath, BDD* parBdd);
void closeBDD(BDD* parBDD);
void store(BDD* parBdd, int parPos, NUPLET parVal);
NUPLET getNupletBdd(BDD parBdd, int parPos);
int size(BDD parBdd);

#endif /* iohelper_h */

