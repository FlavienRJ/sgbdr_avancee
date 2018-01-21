//
//  relation_helper.c
//  sgbd_frj
//
//	Fonction de gestion des relations
//
//  Created by Flavien Ronteix--jacquet on 28/11/2017.
//
//
#include "relation_helper.h"

/** 
 * @brief  Creation d'une nouvelle RELATION
 * @note   
 * @param  attsize: le nombre d'attribut
 * @param  maxsize: la taille maximale de la RELATION
 * @retval Une nouvelle RELATION
 */
RELATION newRELATION(int attsize, int maxsize)
{
	RELATION temp;
	temp.ligne = (NUPLET*) malloc(sizeof(NUPLET)*maxsize);
	temp.sizemax = maxsize;
	temp.size = 0;
	temp.attsize = attsize;
	return temp;
}

/** 
 * @brief  Verifie la compatibilité entre une RELATION et un NUPLET
 * @note   
 * @param  r: la RELATION
 * @param  n: le NUPLET
 * @retval 1 si compatible, 0 sinon
 */
int compatible(RELATION r, NUPLET n)
{
	if(r.attsize == n.size)
		return 1;
	else
		return 0;
}

/** 
 * @brief  Insertion d'un NUPLET dans une RELATION
 * @note   
 * @param  r: la RELATION
 * @param  n: le NUPLET à ajouter
 * @retval None
 */
void insert (RELATION* r, NUPLET n)
{
	if((r->size < r->sizemax) && (compatible(*r,n)==1))
	{
		r->ligne[r->size] = n;
		r->size++;
	}
}

/** 
 * @brief  Insertion à une position d'un NUPLET dans une RELATION
 * @note   
 * @param  r: la RELATION
 * @param  n: le NUPLET à ajouter
 * @param  pos: la position
 * @retval None
 */
void insertPos(RELATION* r, NUPLET n, int pos)
{
	int i;
	if((r->size < r->sizemax) && (compatible(*r,n)==1) && pos >= 0 && pos < (r->size + 1))
	{
		for (i = r->size; i > pos; i--)
		{
			r->ligne[i] = r->ligne[i-1];
		}
		r->ligne[pos] = n;
		r->size++;
	}
}

/** 
 * @brief  Récupération d'un NUPLET dans une RELATION
 * @note   
 * @param  r: La RELATION
 * @param  ligne: La ligne
 * @retval le NUPLET dans la ligne dans la RELATION
 */
NUPLET getNUPLET(RELATION r, int ligne)
{
	if(ligne < r.size)
		return r.ligne[ligne];
	return newErrNUPLET();
}

/** 
 * @brief  Affichage d'une RELATION
 * @note   
 * @param  r: la RELATION
 * @retval None
 */
void afficheRELATION(RELATION r)
{
	int i;
	printf("RELATION === Taille %d sur %d\n================== \n", r.size, r.sizemax);
	for(i=0;i<r.size;i++){
		afficheNUPLET(getNUPLET(r, i));
		printf("\n");
	}
	printf("================== \n");
}

/** 
 * @brief  Parcours les NUPLET d'une RELATION
 * @note   La position du NUPLET renvoyé est sauvegardé entre chaque appel de la fonction et reviens à 0 si le nom de la table est différent
 * @param  r: La RELATION
 * @param  name: Le nom de la RELATION
 * @retval Le prochain NUPLET
 */
NUPLET fullscanNext(const RELATION r, const char* name)
{
	static int pos = 0; //va se rapeller entre chaque appel de la fonction de la position
	static char lastCall[TAILLE_MAX_CHAINE] = "\0"; //va se rappeller entre chaque appel de la fonction du nom de la table
	
	if (strcmp(lastCall, name) != 0)
	{
		strcpy(lastCall, name);
		pos = 0;
	}
	if (pos > r.size)
	{
		printf("Fin de la relation\n");
		return newErrNUPLET();
	}

	NUPLET res = newNUPLET(r.attsize);
	copy(r.ligne[pos], &res);
	pos++;
	return res;
}










