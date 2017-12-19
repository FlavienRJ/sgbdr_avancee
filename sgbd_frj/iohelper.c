#include "iohelper.h"

BDD* newBDD(void)
{
	BDD* res = (BDD*)malloc(sizeof(BDD));
	res->path = "";
	res->data = NULL;
	res->state = 0;
	return res;
}

void openBDD(char* parPath, BDD* parBdd)
{
	
}

void store(BDD* parBdd, int parPos, NUPLET parVal)
{
	
}

NUPLET get(BDD parBdd, int parPos)
{
	NUPLET res;
	res.size=0;
	return res;
}

int size(BDD parBdd)
{
	return 0;
}
