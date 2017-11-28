/*
 * Programme funct.c
 * Création d'une mini base de données en mémoire
 * pour illustrer l'algèbre relationnelle
 */


#include <stdio.h>
#include <stdlib.h>
#include "func.h"

NUPLET newNUPLET(int size){
	NUPLET temp;
	temp.val =  (int*) malloc(sizeof(int)*size);
	temp.size = size;
	return temp;
};

RELATION newRELATION(int attsize, int maxsize){
	RELATION temp;
	temp.ligne = (NUPLET*) malloc(sizeof(NUPLET)*maxsize);
	temp.sizemax = maxsize;
	temp.size = 0;
	temp.attsize = attsize;
	return temp;
}

void set(NUPLET n, int col, int val){
	n.val[col] = val;
}

int get(NUPLET n, int col){
	return n.val[col];
}

int compatible(RELATION r, NUPLET n){
	if(r.attsize == n.size)
		return 1;
	else
		return 0;
}

void insert (RELATION* r, NUPLET n){
	if((r->size < r->sizemax) && (compatible(*r,n)==1)){
		r->ligne[r->size] = n;
		r->size++;
	}
}

NUPLET getNUPLET(RELATION r, int ligne){
	if(ligne < r.size)
		return r.ligne[ligne];
	NUPLET err = newNUPLET(1);
	set(err, 0, -1);
	return err;
}

void afficheNUPLET(NUPLET n){
	int i;
	for(i=0;i<n.size;i++){
		printf("%d ", n.val[i]);
	}
}


void afficheRELATION(RELATION r){
	int i;
	printf("RELATION === Taille %d sur %d\n================== \n", r.size, r.sizemax);
	for(i=0;i<r.size;i++){
		afficheNUPLET(getNUPLET(r, i));
		printf("\n");
	}
	printf("================== \n");
}

/**
 *
 * IMPLEMENTATION DES OPERATEURS
 *
 **/

RELATION OpUnion(RELATION r1, RELATION r2){
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
	NUPLET tmp = newNUPLET(1);
	set(tmp, 0, -1);
	insert(&err, tmp);
	return err;
}


/*
 * Programma principal
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
	
	
	NUPLET n3 = newNUPLET(3);
	set(n3, 0, 3);
	set(n3, 1, 62);
	set(n3, 2, -99);
	
	
	RELATION q = newRELATION(3, 10);
	insert(&q, n3);
	
	RELATION res = OpUnion(q, p);
	afficheRELATION(res);
	
	return 0;
}
