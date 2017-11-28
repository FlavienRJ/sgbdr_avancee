/*
 * INPUT/OUTPUT HELPER
 * GESTION DES FICHIERS
 */


#ifndef iohelper_h
#define iohelper_h

#include <stdio.h>

#include "sgbd.h"

BDD* newBDD(void);
void openBDD(char* parPath, BDD bdd);

#endif /* iohelper_h */

