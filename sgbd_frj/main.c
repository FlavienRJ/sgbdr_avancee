/*
 * Programme funct.c
 * Création d'une mini base de données en mémoire
 * pour illustrer l'algèbre relationnelle
 * ex d'implementation : https://github.com/angelricardoh/sgbd
 */


#include <stdio.h>
#include <stdlib.h>
#include "sgbd.h"
#include "iohelper.h"
#include "nuplet_helper.h"
#include "operateurs.h"

/*
 * Programma principal
 * Demo de ce que fait la sgbd
 */
int main(int argc, char **argv)
{
	printf("Creation d'un nuplet.");
	NUPLET n = newNUPLET(3);
	set(n, 0, 1);
	set(n, 1, 32);
	set(n, 2, -1);
	printf("\n");
	afficheNUPLET(n);
	printf("Creation d'une relation.");
	RELATION p = newRELATION(3, 10);
	insert(&p, n);
	printf("\n");
	afficheRELATION(p);
	
	NUPLET n2 = newNUPLET(3);
	set(n2, 0, 2);
	set(n2, 1, 42);
	set(n2, 2, -15);
	insert(&p, n2);
	printf("\n");
	afficheNUPLET(n2);
	
	
	NUPLET n3 = newNUPLET(3);
	set(n3, 0, 3);
	set(n3, 1, 62);
	set(n3, 2, -99);
	printf("\n");
	afficheNUPLET(n3);
	
	
	RELATION q = newRELATION(3, 10);
	insert(&q, n3);
	
	RELATION res = OpUnion(q, p);
	afficheRELATION(res);
	
	return 0;
}
