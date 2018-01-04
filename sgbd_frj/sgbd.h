/*
 * CORE HEADER
 *
 */

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct nuplet
{
	int* 		val;
	int 		size;
	
} NUPLET;

typedef struct relation
{
	NUPLET* 	ligne;
	int 		attsize;
	int 		size;
	int 		sizemax;
	
} RELATION;

typedef enum operateur
{
	UNION, INTERSECT, WHERE, SELECT, PRODUCT, JOIN
	
} OPERATEUR;

typedef struct operation
{
	OPERATEUR 	op;
	char*		argc;
	int			argv;
	
} OPERATION;

typedef struct requete
{
	OPERATION* 	operations;
	int 		taille;
	
} REQUETE;

typedef struct bdd
{
	char** 		path;
	char** 		noms;
	NUPLET** 	data;
	int 		nbtable;
	int* 		sizetable;
	int			state; //0 = uninitialized, 1 = not read, 2= ready
	
} BDD;

