/*
 * CORE HEADER
 *
 */

#pragma once

#include <stdio.h>


typedef struct nuplet
{
	int* 	val;
	int 	size;
	
} NUPLET;

typedef struct relation
{
	NUPLET* ligne;
	int 	attsize;
	int 	size;
	int 	sizemax;
	
} RELATION;

typedef struct bdd
{
	char* 	path;
	NUPLET* data;
	int		state;
	
} BDD;

/*
 * Opérations pour manipuler les nuplets et les relations
 */

NUPLET newNUPLET(int size);
void set(NUPLET n, int col, int val);
int get(NUPLET n, int col);
int compatible(RELATION r, NUPLET n);
void insert(RELATION* r, NUPLET n);
NUPLET getNUPLET(RELATION r, int ligne);
void afficheRELATION(RELATION r);
void afficheNUPLET(NUPLET n);

/*
 * Opérateurs de l'algèbre relationnelle
 */

RELATION OpUnion(RELATION r1, RELATION r2);
RELATION OpInter(RELATION r1, RELATION r2);
RELATION OpRestrictionCST(RELATION r1, int att, int operateur, int valeur); // operateur : 0 : == ; 1 : < ; 2 : >
RELATION OpRestrictionATT(RELATION r1, int att1, int operateur, int att2);  // idem ici
RELATION OpProjection(RELATION r1, int* attributs, int taille);
RELATION OpProduitCartesien(RELATION r1, RELATION r2);
RELATION OpJointure(RELATION r1, RELATION r2, int attr1, int attr2);

