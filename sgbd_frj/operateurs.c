//
//  operateurs.c
//  sgbd_frj
//
//  Created by Flavien Ronteix--jacquet on 28/11/2017.
//  Copyright © 2017 frj. All rights reserved.
//

#include "operateurs.h"

RELATION OpUnion(RELATION r1, RELATION r2)
{
	RELATION temp = newRELATION(r1.attsize, r1.sizemax + r2.sizemax);
	int i;
	if(r1.attsize == r2.attsize){
		for(i=0;i<r1.size;i++){
			insert(&temp, getNUPLET(r1, i));
		}
		for(i=0;i<r2.size;i++){
			insert(&temp, getNUPLET(r2, i));
		}
		return temp;
	}
	RELATION err = newRELATION(0, 1);
	insert(&err, newErrNUPLET());
	return err;
}

RELATION OpInter(RELATION r1, RELATION r2)
{
	return newRELATION(1, 1);
}

RELATION OpRestrictionCST(RELATION r1, int att, int operateur, int valeur)
{
	return newRELATION(1, 1);
}

RELATION OpRestrictionATT(RELATION r1, int att1, int operateur, int att2)
{
	return newRELATION(1, 1);
}

RELATION OpProjection(RELATION r1, int* attributs, int taille)
{
	int i;
	int j;
	RELATION res = newRELATION(taille, r1.size);
	NUPLET tmp = newNUPLET(taille);
	for (i=0; i < r1.size; i++)
	{
		for (j=0; j < taille; j++)
		{
			set(tmp, j, get(getNUPLET(r1, i), attributs[j]));
		}
		insert(&res, tmp);
	}
	return res;
}

RELATION OpProduitCartesien(RELATION r1, RELATION r2)
{
	int i;
	int j;
	int k;
	int l;
	RELATION res = newRELATION((r1.attsize + r2.attsize), (r1.size*r2.size));
	NUPLET tmp = newNUPLET(r1.attsize + r2.attsize);
	
	for (i=0; i < r2.size; i++)
	{
		for (k=0; k < r2.attsize; k++)
		{
			//On set les attributs de la relation r2
			set(tmp, k + r1.attsize, get(getNUPLET(r2, i), k));
		}
		for (j=0; j < r1.size; j++)
		{
			//Pour tous les élements de la relation r1
			for (l=0; l < r1.attsize; l++)
			{
				//on set les attibuts de la relation r1
				set(tmp, l, get(getNUPLET(r1, j), l));
			}
			insert(&res, tmp);
		}
	}
	return res;
}

RELATION OpJointure(RELATION r1, RELATION r2, int attr1, int attr2)
{
	return newRELATION(1, 1);
}

















