//
//  nuplet_helper.c
//  sgbd_frj
//	Gestion des NUPLET
//  

#include "nuplet_helper.h"

/** 
 * @brief  Création d'un NUPLET
 * @note   
 * @param  size: nb d'attribut
 * @retval retourne un NUPLET
 */
NUPLET newNUPLET(int size)
{
	NUPLET temp;
	temp.val =  (int*) malloc(sizeof(int)*size);
	temp.size = size;
	return temp;
}

/** 
 * @brief  Ecriture d'un attribut d"un NUPLET
 * @note   
 * @param  n: le NUPLET
 * @param  col: l'attribut
 * @param  val: la nouvelle valeur de l'attribut
 * @retval None
 */
void set(NUPLET n, int col, int val)
{
	n.val[col] = val;
}

/** 
 * @brief Lecture d'un attribut d'un NUPLET 
 * @note   
 * @param  n: le NUPLET	
 * @param  col: l'attribut à lire
 * @retval 
 */
int get(NUPLET n, int col)
{
	return n.val[col];
}

/** 
 * @brief  Copie d'un NUPLET vers un autre
 * @note   
 * @param  org: le NUPLET source	
 * @param  cpy: le NUPLET destination
 * @retval None
 */
void copy(const NUPLET org, NUPLET* cpy)
{
	int i;
	for (i=0; i < org.size; i++)
	{
		set(*cpy, i, get(org, i));
	}
}

/** 
 * @brief  Création d'un NUPLET d'erreur pour la gestion des erreurs
 * @note   
 * @retval 
 */
NUPLET newErrNUPLET(void)
{
	NUPLET err = newNUPLET(1);
	set(err, 0, -1);
	return err;
}

/** 
 * @brief  Cherche un NUPLET dans une relation
 * @note   
 * @param  r: la relation
 * @param  att: un tableau d'attribut pour trouver un NUPLET
 * @retval la position si le NUPLET existe, -1 sinon
 */
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

/** 
 * @brief  Affichage d'un NUPLE
 * @note   
 * @param  n: le NUPLET
 * @retval None
 */
void afficheNUPLET(NUPLET n)
{
	int i;
	for(i=0;i<n.size;i++){
		printf("%d ", n.val[i]);
	}
}

