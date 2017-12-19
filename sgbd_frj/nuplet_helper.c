//
//  nuplet_helper.c
//  sgbd_frj
//
//  Created by Flavien Ronteix--jacquet on 19/12/2017.
//  Copyright © 2017 frj. All rights reserved.
//

#include "nuplet_helper.h"

NUPLET newNUPLET(int size){
	NUPLET temp;
	temp.val =  (int*) malloc(sizeof(int)*size);
	temp.size = size;
	return temp;
};

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

void afficheRELATION(RELATION r){
	int i;
	printf("RELATION === Taille %d sur %d\n================== \n", r.size, r.sizemax);
	for(i=0;i<r.size;i++){
		afficheNUPLET(getNUPLET(r, i));
		printf("\n");
	}
	printf("================== \n");
}


void afficheNUPLET(NUPLET n){
	int i;
	for(i=0;i<n.size;i++){
		printf("%d ", n.val[i]);
	}
}

