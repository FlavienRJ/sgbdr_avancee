#include "iohelper.h"

BDD* newBDD(void)
{
	BDD* res = (BDD*)malloc(sizeof(BDD));
	res->path = "";
	res->data = NULL;
	res->state = 0;
	return res;
}

int openBDD(char* parPath, BDD* parBdd)
{
	//On ouvre le fichier
	FILE * fp;
	if ((fp = fopen(parPath, "w+")) == NULL)
	{
		return -1;
	}
	parBdd->path = parPath;
	parBdd->state = 1;
	
	//On lit la taille du nuplet sur la premiere ligne de la bdd
	
	//On lit toutes les lignes du fichier que l'on stocke dans des nuplets
	char *row;
	int ret;
	NUPLET tmp;
	while ((ret = fscanf (fp,"%s ",row)) != EOF && ret != 0)
	{
		
		while (strsep(&row, ";"))
		{
			
		}
		printf("%s", row);
	}
	
	return 0;
}

void closeBDD(BDD* parBDD)
{
	
}

void store(BDD* parBdd, int parPos, NUPLET parVal)
{
	
}

NUPLET getNupletBdd(BDD parBdd, int parPos)
{
	NUPLET res;
	res.size=0;
	return res;
}

int size(BDD parBdd)
{
	return 0;
}
