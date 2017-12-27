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
