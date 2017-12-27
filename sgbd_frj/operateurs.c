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
	NUPLET tmp = newNUPLET(1);
	set(tmp, 0, -1);
	insert(&err, tmp);
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
	return newRELATION(1, 1);
}

RELATION OpProduitCartesien(RELATION r1, RELATION r2)
{
	return newRELATION(1, 1);
}

RELATION OpJointure(RELATION r1, RELATION r2, int attr1, int attr2)
{
	return newRELATION(1, 1);
}










