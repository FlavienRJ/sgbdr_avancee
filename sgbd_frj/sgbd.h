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
	int		state; //0 = uninitialized, 1 = ready
	
} BDD;

