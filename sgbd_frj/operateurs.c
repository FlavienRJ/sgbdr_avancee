//
//  operateurs.c
//  sgbd_frj
//
//  Created by Flavien Ronteix--jacquet on 28/11/2017.
//  Copyright © 2017 frj. All rights reserved.
//

#include "operateurs.h"

/** 
 * @brief  operation d'UNION
 * @note  SELECT * FROM r1 UNION SELECT * FROM r2; 
 * @param  r1: 
 * @param  r2: 
 * @retval 
 */
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

/** 
 * @brief  operation Intersection
 * @note   SELECT * FROM r1 INTERSECT SELECT * FROM r2;
 * @param  r1: 
 * @param  r2: 
 * @retval 
 */
RELATION OpInter(RELATION r1, RELATION r2)
{
	if (r1.attsize != r2.attsize)
	{
		RELATION err = newRELATION(0, 1);
		insert(&err, newErrNUPLET());
		return err;
	}
	
	int i;
	int j;
	int k;
	bool identique;
	RELATION res = newRELATION(r1.attsize, r1.sizemax);
	
	//A OPTIMISER ABSOLUMENT SUR LES BOUCLES
	for (i=0; i < r1.size; i++)
	{
		for (j=0; j < r2.size; j++)
		{
			identique = true;
			for (k=0; k < r1.attsize; k++)
			{
				if (r1.ligne[i].val[k] != r2.ligne[j].val[k])
				{
					identique = false;
					break;
				}
			}
			if (identique)
			{
				NUPLET tmp = newNUPLET(r1.attsize);
				copy(r1.ligne[i], &tmp);
				insert(&res, tmp);
			}
		}
	}
	return res;
}

/** 
 * @brief  Operateur de Restriction pour une valeur fixe
 * @note   SELECT * FROM r1 WHERE r1.att operateur(<,=,...) valeur
 * @param  r1: 
 * @param  att: 
 * @param  operateur: 0 = "==", 1 = "<", 2 = ">", 3 = "!="
 * @param  valeur: 
 * @retval 
 */
RELATION OpRestrictionCST(RELATION r1, int att, int operateur, int valeur)
{
	int i;
	int j;
	if (att > r1.attsize)
	{
		RELATION err = newRELATION(0, 1);
		insert(&err, newErrNUPLET());
		return err;
	}
	RELATION res = newRELATION(r1.attsize, r1.size);
	NUPLET tmp = newNUPLET(r1.attsize);
	switch (operateur)
	{
	    //Operateur "=="
		case 0:
			for (i=0; i < r1.size; i++)
			{
				if (r1.ligne[i].val[att] == valeur)
				{
					for (j=0; j < r1.attsize; j++)
					{
						set(tmp, j, get(getNUPLET(r1, i), j));
					}
					insert(&res, tmp);
				}
			}
			break;
		
		//Operateur "<"
		case 1:
			for (i=0; i < r1.size; i++)
			{
				if (r1.ligne[i].val[att] < valeur)
				{
					for (j=0; j < r1.attsize; j++)
					{
						set(tmp, j, get(getNUPLET(r1, i), j));
					}
					insert(&res, tmp);
				}
			}
			break;
		
		//Operateur ">"
		case 2:
			for (i=0; i < r1.size; i++)
			{
				if (r1.ligne[i].val[att] > valeur)
				{
					for (j=0; j < r1.attsize; j++)
					{
						set(tmp, j, get(getNUPLET(r1, i), j));
					}
					insert(&res, tmp);
				}
			}
			break;
		
		//Operateur "!="
		case 3:
			for (i=0; i < r1.size; i++)
			{
				if (r1.ligne[i].val[att] != valeur)
				{
					for (j=0; j < r1.attsize; j++)
					{
						set(tmp, j, get(getNUPLET(r1, i), j));
					}
					insert(&res, tmp);
				}
			}
			break;
			
		default:
			//Si ce n'est pas un operateur alors la RELATION sera VIDE (taille = 0)
			break;
	}

	return res;
}

/** 
 * @brief  Operateur de Restriction pour une valeur variable
 * @note   SELECT * FROM r1 WHERE r1.att operateur(<,=,...) r1.att2
 * @param  r1: 
 * @param  att1: 
 * @param  operateur: 0 = "==", 1 = "<", 2 = ">", 3 = "!="
 * @param  att2: 
 * @retval 
 */
RELATION OpRestrictionATT(RELATION r1, int att1, int operateur, int att2)
{
	int i;
	int j;
	if (att1 > r1.attsize || att2 > r1.attsize)
	{
		RELATION err = newRELATION(0, 1);
		insert(&err, newErrNUPLET());
		return err;
	}
	RELATION res = newRELATION(r1.attsize, r1.size);
	NUPLET tmp = newNUPLET(r1.attsize);
	switch (operateur)
	{
			//Operateur "=="
		case 0:
			for (i=0; i < r1.size; i++)
			{
				if (r1.ligne[i].val[att1] == r1.ligne[i].val[att2])
				{
					for (j=0; j < r1.attsize; j++)
					{
						set(tmp, j, get(getNUPLET(r1, i), j));
					}
					insert(&res, tmp);
				}
			}
			break;
			
			//Operateur "<"
		case 1:
			for (i=0; i < r1.size; i++)
			{
				if (r1.ligne[i].val[att1] < r1.ligne[i].val[att2])
				{
					for (j=0; j < r1.attsize; j++)
					{
						set(tmp, j, get(getNUPLET(r1, i), j));
					}
					insert(&res, tmp);
				}
			}
			break;
			
			//Operateur ">"
		case 2:
			for (i=0; i < r1.size; i++)
			{
				if (r1.ligne[i].val[att1] > r1.ligne[i].val[att2])
				{
					for (j=0; j < r1.attsize; j++)
					{
						set(tmp, j, get(getNUPLET(r1, i), j));
					}
					insert(&res, tmp);
				}
			}
			break;
			
			//Operateur "!="
		case 3:
			for (i=0; i < r1.size; i++)
			{
				if (r1.ligne[i].val[att1] != r1.ligne[i].val[att2])
				{
					for (j=0; j < r1.attsize; j++)
					{
						set(tmp, j, get(getNUPLET(r1, i), j));
					}
					insert(&res, tmp);
				}
			}
			break;
			
		default:
			//Si ce n'est pas un operateur alors la RELATION sera VIDE (taille = 0)
			break;
	}
	
	return res;
}

/** 
 * @brief  Operateur de projection
 * @note   SELECT attributs FROM r1;
 * @param  r1: 
 * @param  attributs: 
 * @param  taille: 
 * @retval 
 */
RELATION OpProjection(RELATION r1, int* attributs, int taille)
{
	int i;
	int j;
	RELATION res = newRELATION(taille, r1.sizemax);
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

/** 
 * @brief  Operateur de produit cartesien
 * @note   SELECT * FROM r1,r2;
 * @param  r1: 
 * @param  r2: 
 * @retval 
 */
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

/** 
 * @brief  Operateur de jointure entre 2 relations
 * @note   SELECT * FROM r1, r2 WHERE r1.attr1 = r2.attr2;
 * @param  r1: 
 * @param  r2: 
 * @param  attr1: 
 * @param  attr2: 
 * @retval 
 */
RELATION OpJointure(RELATION r1, RELATION r2, int attr1, int attr2)
{
	int i;
	int j;
	int k;
	int maxsize = (r1.sizemax > r2.sizemax) ? r1.sizemax : r2.sizemax;
	RELATION res = newRELATION((r1.attsize + r2.attsize - 1), maxsize);
	NUPLET tmp = newNUPLET(r1.attsize + r2.attsize - 1);
	
	for (i=0; i < r1.size; i++)
	{
		for (j=0; j < r2.size; j++)
		{
			if (r1.ligne[i].val[attr1] == r2.ligne[j].val[attr2])
			{
				for (k=0; k < r1.attsize; k++)
				{
					set(tmp, k, r1.ligne[i].val[k]);
				}
				for (k=0; k < r2.attsize; k++)
				{
					if (k != attr2)
					{
						set(tmp, k + r1.attsize, r2.ligne[j].val[k]);
					}
				}
				insert(&res, tmp);
			}
		}
	}
	return res;
}

RELATION OpJointureHash(RELATION r1, RELATION r2, int attr1, int attr2)
{
	int i;
	int j;
	int k;
	int l;
	int maxsize = (r1.sizemax > r2.sizemax) ? r1.sizemax : r2.sizemax;
	RELATION res = newRELATION((r1.attsize + r2.attsize - 1), maxsize);
	NUPLET tmp = newNUPLET(r1.attsize + r2.attsize - 1);
	TABLE_HASH hash_table;
	for (l = 0; l < TAILLE_HASH; l++)
	{
		hash_table.table[l] = NULL;
		hash_table.size_table[l] = 0;
	}

	bool r1_plue_petit = (r1.size > r2.size) ? false : true;
	if(r1_plue_petit)
	{
		for (i=0; i<r1.size; i++)
		{
			insertHash(&hash_table, r1.ligne[i].val[attr1], r1.ligne[i]);
		}
		for (j=0; j < r2.size; j++)
		{
			for (k=0; k < hash_table.size_table[hashCode(r2.ligne[j].val[attr1])]; k++)
			{
				if (/*r.attr1 = r2.ligne[j].val[attr2]*/)
				{
					for (k=0; k < r1.attsize; k++)
					{
						set(tmp, k, r1.ligne[i].val[k]);
					}
					for (k=0; k < r2.attsize; k++)
					{
						if (k != attr2)
						{
							set(tmp, k + r1.attsize, r2.ligne[j].val[k]);
						}
					}
					insert(&res, tmp);
				}
			}
		}
	}
	else
	{
		for (i=0; i<r2.size; i++)
		{
			//mettre r2[i] dans le bucket numero hash(r2.attr2)
		}
	}

	return res;
}

int hashCode(const int clef)
{
	return clef % TAILLE_HASH;
}

//On ajoute dans une liste chainée
void insertHash(TABLE_HASH* hash_table, int clef, NUPLET data)
{
	int HashIndex = hashCode(clef);
	ITEM_HASH * tmp = (ITEM_HASH*)malloc(sizeof(ITEM_HASH));
	tmp->clef = clef;
	copy(data, &tmp->data);
	tmp->next = NULL;
	ITEM_HASH* i = hash_table->table[HashIndex];
	while (i->next != NULL)
	{
		i = i->next;
	}
	i->next = tmp;
	hash_table->size_table[HashIndex]++;
}














