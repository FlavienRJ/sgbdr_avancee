/*
 * FONCTION DE PARSING DES REQUETES DECLARATIVES
 */


#ifndef parsing_h
#define parsing_h

#include <stdio.h>
#include "sgbd.h"

int getInput(char** raw);
int parseInput(char*** rawToken, char** raw, int taille);
int getCommand(char*** rawToken, REQUETE* listeOperation, int nbRequete);

#endif /* parsing_h */
