//
//  nuplet_helper.c
//  sgbd_frj
//
//  Created by Flavien Ronteix--jacquet on 19/12/2017.
//  Copyright © 2017 frj. All rights reserved.
//

#include "nuplet_helper.h"

NUPLET newNUPLET(int size)
{
	NUPLET temp;
	temp.val =  (int*) malloc(sizeof(int)*size);
	temp.size = size;
	return temp;
}

void set(NUPLET n, int col, int val)
{
	n.val[col] = val;
}

int get(NUPLET n, int col)
{
	return n.val[col];
}

void copy(const NUPLET org, NUPLET* cpy)
{
	int i;
	for (i=0; i < org.size; i++)
	{
		set(*cpy, i, get(org, i));
	}
}

NUPLET newErrNUPLET(void)
{
	NUPLET err = newNUPLET(1);
	set(err, 0, -1);
	return err;
}

//Retourne la position du premier NUPLET contenant les valeurs de att s'il existe, -1 sinon
int findNuplet(const RELATION r, const int* att)
{
	int i;
	int j;
	bool is;
	
	for (i=0; i < r.size; i++)
	{
		is = true;
		for (j=0; j < r.attsize; j++)
		{
			if (get(r.ligne[i], j) != att[j])
			{
				is = false;
			}
			if (!is)
			{
				break;
			}
		}
		if (is)
		{
			return i;
		}
	}
	return -1;
}

void afficheNUPLET(NUPLET n)
{
	int i;
	for(i=0;i<n.size;i++){
		printf("%d ", n.val[i]);
	}
}

