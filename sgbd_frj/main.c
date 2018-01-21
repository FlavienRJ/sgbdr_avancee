#include <stdio.h>
#include <stdlib.h>
#include "sgbd.h"
#include "iohelper.h"
#include "nuplet_helper.h"
#include "operateurs.h"
#include "journalisation.h"
#include "parser.h"

/*
 * Programma principal
 * Demo de ce que fait la sgbd
 */
int main(int argc, char **argv)
{
    BDD* bdd = newBDD(10);
    
	//printf("Creation d'un nuplet.");
	NUPLET n = newNUPLET(3);
	set(n, 0, 1);
	set(n, 1, 32);
	set(n, 2, -1);
	printf("\n");
	//afficheNUPLET(n);
	//printf("Creation d'une relation.");
    
	//RELATION
	bdd->data[0] = newRELATION(3, 10);
    //bdd->data[0]=p;
	insert(&bdd->data[0], n);
	//printf("\n");
	//afficheRELATION(bdd->data[0]);
	
	NUPLET n2 = newNUPLET(3);
	set(n2, 0, 2);
	set(n2, 1, 42);
	set(n2, 2, -15);
	insert(&bdd->data[0], n2);
	//printf("\n");
	//afficheNUPLET(n2);
	
	
	NUPLET n3 = newNUPLET(3);
	set(n3, 0, 3);
	set(n3, 1, 62);
	set(n3, 2, -99);
	//printf("\n");
	//afficheNUPLET(n3);
	
	
	bdd->data[1] = newRELATION(3, 10);
	insert(&bdd->data[1], n3);

	bdd->data[2] = newRELATION(3, 10);
	insert(&bdd->data[2], n3);
	
	bdd->data[3] = OpUnion(bdd->data[1], bdd->data[0]);
	afficheRELATION(bdd->data[3]);

	printf("Operateur de projection\n");
	int attr[2] = {0, 2};
	afficheRELATION(OpProjection(bdd->data[3], attr, 2));

	printf("Operateur cartesien\n");
	afficheRELATION(OpProduitCartesien(bdd->data[1], bdd->data[3]));

	printf("Operateur Intersection\n");
	afficheRELATION(OpProduitCartesien(bdd->data[1], bdd->data[2]));

	printf("Operateur Restriction constant\n");
	afficheRELATION(OpRestrictionCST(bdd->data[0], 1, 0, 42));

	printf("Operateur Jointure\n");
	afficheRELATION(OpJointure(bdd->data[3], bdd->data[1], 1, 1));

	afficheRELATION(parser(argc, argv, bdd));
    
    

	
	return 0;
}
