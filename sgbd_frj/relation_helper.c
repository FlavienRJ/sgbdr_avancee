#include "relation_helper.h"

RELATION newRELATION(int attsize, int maxsize)
{
	RELATION temp;
	temp.ligne = (NUPLET*) malloc(sizeof(NUPLET)*maxsize);
	temp.sizemax = maxsize;
	temp.size = 0;
	temp.attsize = attsize;
	return temp;
}

int compatible(RELATION r, NUPLET n)
{
	if(r.attsize == n.size)
		return 1;
	else
		return 0;
}

void insert (RELATION* r, NUPLET n)
{
	if((r->size < r->sizemax) && (compatible(*r,n)==1))
	{
		r->ligne[r->size] = n;
		r->size++;
	}
}

void insertPos(RELATION* r, NUPLET n, int pos)
{
	int i;
	if((r->size < r->sizemax) && (compatible(*r,n)==1) && pos > 0 && pos < (r->size + 1))
	{
		for (i = r->size; i > pos; i++)
		{
			r->ligne[i] = r->ligne[i-1];
		}
		r->ligne[pos] = n;
		r->size++;
	}
}

NUPLET getNUPLET(RELATION r, int ligne)
{
	if(ligne < r.size)
		return r.ligne[ligne];
	return newErrNUPLET();
}

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










