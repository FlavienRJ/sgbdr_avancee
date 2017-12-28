/*
 * CORE HEADER
 *
 */

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
	char** 	path;
	char** 	noms;
	NUPLET** data;
	int 	nbtable;
	int* 	sizetable;
	int		state; //0 = uninitialized, 1 = not read, 2= ready
	
} BDD;

