//
//  indexation.c
//  sgbd_frj
//
//  Permet la convertion des Relation en Relation indexée
//

#include "indexation.h"

/** 
 * @brief  Convertie une relation en relation indexée
 * @note   
 * @param  org: la relation originale
 * @retval la même relation mais avec un index sur les NUPLET
 */
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

/** 
 * @brief  convertie un NUPLET en NUPLET avec numero d'index
 * @note   
 * @param  org: le NUPLET originale
 * @retval la NUPLET convertie
 */
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
