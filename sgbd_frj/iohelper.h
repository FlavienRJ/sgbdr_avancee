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
#include "relation_helper.h"

BDD* newBDD(void);
int openTable(char* parPath, char* parName, BDD* parBdd);
int closeBDD(BDD* parBDD);
int store(BDD* parBdd, const char* parTable, int parPos, NUPLET parVal);
NUPLET getNupletBdd(BDD parBdd,const char* parTable, int parPos);
int size(BDD parBdd, const char* parTable);
int tableDansBdd(const BDD parBdd, const char* parTable);
void printTable(const BDD parBdd, const char* parTable);

#endif /* iohelper_h */

