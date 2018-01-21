//
//  indexation.c
//  sgbd_frj
//
//  Permet la convertion des Relation en Relation indexée
//

#include "indexation.h"


RELATION_INDEX convertToIndex(const RELATION org)
{
	int i;
	int j;
	RELATION_INDEX tmp;

	tmp.attsize 	= org.attsize;
	tmp.size 		= org.size;
	tmp.sizemax 	= org.sizemax;

	for (i=0; i < org.size; i++)
	{
		tmp.ligne[i].index = i;
		tmp.ligne[i].size = tmp.ligne[i].size;
		for (j=0; j < tmp.attsize; j++)
		{
			tmp.ligne[i].val[j] = org.ligne[i].val[j];
		}
	}
	return tmp;
}


NUPLET convertToNuplet(const NUPLET_INDEX org)
{
	NUPLET tmp = newNUPLET(org.size+1);
	tmp.val[0] = org.index;

	int i;
	for (i=0; i < org.size; i++)
	{
		tmp.val[i+1] = org.val[i];
	}
	return tmp;
}
