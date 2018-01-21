//
//  operateurs.c
//  sgbd_frj
//
//  Created by Flavien Ronteix--jacquet on 28/11/2017.
//  Copyright © 2017 frj. All rights reserved.
//

#include "operateurs.h"

/** 
 * @brief  operation d'UNION OK
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
 * @brief  operation Intersection PRESQUE
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
 * @brief  Operateur de Restriction pour une valeur fixe OK
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

	switch (operateur)
	{
	    //Operateur "=="
		case 0:
			for (i=0; i < r1.size; i++)
			{
				NUPLET tmp = newNUPLET(r1.attsize);
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
				NUPLET tmp = newNUPLET(r1.attsize);
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
				NUPLET tmp = newNUPLET(r1.attsize);
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
				NUPLET tmp = newNUPLET(r1.attsize);
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
 * @brief  Operateur de Restriction pour une valeur variable OK
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

	switch (operateur)
	{
			//Operateur "=="
		case 0:
			for (i=0; i < r1.size; i++)
			{
				NUPLET tmp = newNUPLET(r1.attsize);
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
				NUPLET tmp = newNUPLET(r1.attsize);
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
				NUPLET tmp = newNUPLET(r1.attsize);
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
				NUPLET tmp = newNUPLET(r1.attsize);
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
 * @brief  Operateur de projection OK
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

	for (i=0; i < r1.size; i++)
	{
		NUPLET tmp = newNUPLET(taille);
		for (j=0; j < taille; j++)
		{
			set(tmp, j, get(getNUPLET(r1, i), attributs[j]));
		}
		insert(&res, tmp);
	}
	return res;
}

/** 
 * @brief  Operateur de produit cartesien OK
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
	
	for (i=0; i < r2.size; i++)
	{
		NUPLET tmp = newNUPLET(r1.attsize + r2.attsize);
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

		}
		insert(&res, tmp);
	}
	return res;
}

/** 
 * @brief  Operateur de jointure entre 2 relations PRESQUE
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

	
	for (i=0; i < r1.size; i++)
	{
		for (j=0; j < r2.size; j++)
		{
			NUPLET tmp = newNUPLET(r1.attsize + r2.attsize - 1);
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

/** 
 * @brief  Operateur de Jointure Hash Join
 * @note   
 * @param  r1: 
 * @param  r2: 
 * @param  attr1: 
 * @param  attr2: 
 * @retval 
 */
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
				/*r.attr1 = r2.ligne[j].val[attr2]*/
				if (hash_table.table[k]->data.val[attr1] == r2.ligne[j].val[attr2])
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
			insertHash(&hash_table, r2.ligne[i].val[attr1], r2.ligne[i]);
		}
		for (j=0; j < r1.size; j++)
		{
			for (k=0; k < hash_table.size_table[hashCode(r1.ligne[j].val[attr1])]; k++)
			{
				/*r.attr1 = r1.ligne[j].val[attr2]*/
				if (hash_table.table[k]->data.val[attr1] == r1.ligne[j].val[attr2])
				{
					for (k=0; k < r2.attsize; k++)
					{
						set(tmp, k, r2.ligne[i].val[k]);
					}
					for (k=0; k < r1.attsize; k++)
					{
						if (k != attr2)
						{
							set(tmp, k + r2.attsize, r1.ligne[j].val[k]);
						}
					}
					insert(&res, tmp);
				}
			}
		}
	}
	return res;
}

/** 
 * @brief  Operateur de jointure par Sort Merge
 * @note   
 * @param  r1: 
 * @param  r2: 
 * @param  attr1: 
 * @param  attr2: 
 * @retval 
 */
RELATION OpJointureSortMerge(RELATION r1, RELATION r2, int attr1, int attr2)
{
	int maxsize = (r1.sizemax > r2.sizemax) ? r1.sizemax : r2.sizemax;
	RELATION res = newRELATION((r1.attsize + r2.attsize - 1), maxsize);
	NUPLET tmp = newNUPLET(r1.attsize + r2.attsize - 1);

	//Stage 1 : Tri
	RELATION r1_trie = insertionSort(r1, attr1);
	RELATION r2_trie = insertionSort(r2, attr2);

	//Stage 2 : Merge
	NUPLET tmp1 = r1_trie.ligne[0];
	NUPLET tmp2 = r2_trie.ligne[0];

	int r = 0;
	int r_2 = 0;
	int q = 0;
	int q_2 = 0;

	int k;

	while (r < r1_trie.size && q < r2_trie.size)
	{
		if (tmp1.val[attr1] > tmp2.val[attr2])
		{
			q++;
			tmp2 = r2_trie.ligne[q];
		}
		else if (tmp1.val[attr1] < tmp2.val[attr2])
		{
			r++;
			tmp1 = r1_trie.ligne[r];
		}
		else
		{
			//on met p◦q dans la relation res
			for (k=0; k < r1.attsize; k++)
			{
				set(tmp, k, r1_trie.ligne[r].val[k]);
			}
			for (k=0; k < r2.attsize; k++)
			{
				if (k != attr2)
				{
					set(tmp, k + r1.attsize, r2_trie.ligne[q].val[k]);
				}
			}
			insert(&res, tmp);


			q_2 = q++;
			while (q_2 < r1.size && r1_trie.ligne[r].val[attr1] == r2_trie.ligne[q_2].val[attr2])
			{
				for (k=0; k < r1.attsize; k++)
				{
					set(tmp, k, r1_trie.ligne[r].val[k]);
				}
				for (k=0; k < r2.attsize; k++)
				{
					if (k != attr2)
					{
						set(tmp, k + r1.attsize, r2_trie.ligne[q_2].val[k]);
					}
				}
				insert(&res, tmp);
			}


			r_2 = r++;
			while (r_2 < r1.size && r1_trie.ligne[r_2].val[attr1] == r2_trie.ligne[q].val[attr2])
			{
				for (k=0; k < r1.attsize; k++)
				{
					set(tmp, k, r1_trie.ligne[r_2].val[k]);
				}
				for (k=0; k < r2.attsize; k++)
				{
					if (k != attr2)
					{
						set(tmp, k + r1.attsize, r2_trie.ligne[q].val[k]);
					}
				}
				insert(&res, tmp);
			}


			r++;
			q++;
		}
	}

	return res;
}


/** 
 * @brief  Calcul d'un hash pour une clef
 * @note   Methode la plus simple avec le modulo
 * @param  clef: 
 * @retval 
 */
int hashCode(const int clef)
{
	return clef % TAILLE_HASH;
}

/** 
 * @brief  Ajouter un NUPLET à une table de Hash par méthode la liste chainée
 * @note   
 * @param  hash_table: la table de Hash
 * @param  clef: la clef (calculé avec hashCode)
 * @param  data: la NUPLET
 * @retval None
 */
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

/** 
 * @brief  Tri par insertionSort d'une relation
 * @note   
 * @param  r: la Relation à trier
 * @param  attr: l'attribut sur lequel trier
 * @retval une Relation trié
 */
RELATION insertionSort(RELATION r, int attr)
{
	RELATION res = newRELATION(r.attsize, r.size);
	res = r; //Pas sûr que cette copie fonctionne

	//On fait le tri avec un insertion sort
	NUPLET tmp = newNUPLET(r.attsize);
	int holePosition;
	int i;

	for (i = 1; i < r.size; i++)
	{
		copy(res.ligne[i], &tmp);
		holePosition = i;

		while (holePosition > 0 && res.ligne[holePosition - 1].val[attr] > tmp.val[attr])
		{
			res.ligne[holePosition] = res.ligne[holePosition - 1];
			holePosition--;
		}

		if (holePosition != i)
		{
			res.ligne[holePosition] = tmp;
		}
	}
	return res;
}

/**
 * @brief  Tri par bubbleSort d'une relation
 * @note
 * @param  r: la Relation à trier
 * @param  attr: l'attribut sur lequel trier
 * @retval une Relation trié
 */
RELATION bubbleSortR(RELATION r, int attr)
{
	RELATION res = newRELATION(r.attsize, r.sizemax);

	int i,j;
	printf("Test1\n");
	afficheRELATION(res);
	res.size = r.size;

	for (i=0; i < r.size - 1; i++)
	{
		for (j=0; j < (r.size - i - 1); j++)
		{
			if (get(getNUPLET(r, j), attr) > get(getNUPLET(r, j + 1), attr))
			{
				res.ligne[j] =getNUPLET(r, j+1);
				res.ligne[j+1] = getNUPLET(r, j);
			}
			printf("i : %d, j : %d\n", i,j);
			afficheRELATION(res);
		}
	}
	return res;
}














