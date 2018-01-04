//
//  operateurs.c
//  sgbd_frj
//
//  Created by Flavien Ronteix--jacquet on 28/11/2017.
//  Copyright © 2017 frj. All rights reserved.
//

#include "operateurs.h"

//SELECT * FROM r1 UNION SELECT * FROM r2;
RELATION OpUnion(RELATION r1, RELATION r2)
{
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
	insert(&err, newErrNUPLET());
	return err;
}

//SELECT * FROM r1 INTERSECT SELECT * FROM r2;
RELATION OpInter(RELATION r1, RELATION r2)
{
	if (r1.attsize != r2.attsize)
	{
		RELATION err = newRELATION(0, 1);
		insert(&err, newErrNUPLET());
		return err;
	}
	
	int i;
	int j;
	int k;
	bool identique;
	RELATION res = newRELATION(r1.attsize, r1.sizemax);
	
	//A OPTIMISER ABSOLUMENT SUR LES BOUCLES
	for (i=0; i < r1.size; i++)
	{
		for (j=0; j < r2.size; j++)
		{
			identique = true;
			for (k=0; k < r1.attsize; k++)
			{
				if (r1.ligne[i].val[k] != r2.ligne[j].val[k])
				{
					identique = false;
					break;
				}
			}
			if (identique)
			{
				NUPLET tmp = newNUPLET(r1.attsize);
				copy(r1.ligne[i], &tmp);
				insert(&res, tmp);
			}
		}
	}
	return res;
}

//SELECT * FROM r1 WHERE r1.att operateur(<,=,...) valeur
RELATION OpRestrictionCST(RELATION r1, int att, int operateur, int valeur)
{
	int i;
	int j;
	if (att > r1.attsize)
	{
		RELATION err = newRELATION(0, 1);
		insert(&err, newErrNUPLET());
		return err;
	}
	RELATION res = newRELATION(r1.attsize, r1.size);
	NUPLET tmp = newNUPLET(r1.attsize);
	switch (operateur)
	{
	    //Operateur "=="
		case 0:
			for (i=0; i < r1.size; i++)
			{
				if (r1.ligne[i].val[att] == valeur)
				{
					for (j=0; j < r1.attsize; j++)
					{
						set(tmp, j, get(getNUPLET(r1, i), j));
					}
					insert(&res, tmp);
				}
			}
			break;
		
		//Operateur "<"
		case 1:
			for (i=0; i < r1.size; i++)
			{
				if (r1.ligne[i].val[att] < valeur)
				{
					for (j=0; j < r1.attsize; j++)
					{
						set(tmp, j, get(getNUPLET(r1, i), j));
					}
					insert(&res, tmp);
				}
			}
			break;
		
		//Operateur ">"
		case 2:
			for (i=0; i < r1.size; i++)
			{
				if (r1.ligne[i].val[att] > valeur)
				{
					for (j=0; j < r1.attsize; j++)
					{
						set(tmp, j, get(getNUPLET(r1, i), j));
					}
					insert(&res, tmp);
				}
			}
			break;
		
		//Operateur "!="
		case 3:
			for (i=0; i < r1.size; i++)
			{
				if (r1.ligne[i].val[att] != valeur)
				{
					for (j=0; j < r1.attsize; j++)
					{
						set(tmp, j, get(getNUPLET(r1, i), j));
					}
					insert(&res, tmp);
				}
			}
			break;
			
		default:
			//Si ce n'est pas un operateur alors la RELATION sera VIDE (taille = 0)
			break;
	}

	return res;
}

//SELECT * FROM r1 WHERE r1.att operateur(<,=,...) r1.att2
RELATION OpRestrictionATT(RELATION r1, int att1, int operateur, int att2)
{
	int i;
	int j;
	if (att1 > r1.attsize || att2 > r1.attsize)
	{
		RELATION err = newRELATION(0, 1);
		insert(&err, newErrNUPLET());
		return err;
	}
	RELATION res = newRELATION(r1.attsize, r1.size);
	NUPLET tmp = newNUPLET(r1.attsize);
	switch (operateur)
	{
			//Operateur "=="
		case 0:
			for (i=0; i < r1.size; i++)
			{
				if (r1.ligne[i].val[att1] == r1.ligne[i].val[att2])
				{
					for (j=0; j < r1.attsize; j++)
					{
						set(tmp, j, get(getNUPLET(r1, i), j));
					}
					insert(&res, tmp);
				}
			}
			break;
			
			//Operateur "<"
		case 1:
			for (i=0; i < r1.size; i++)
			{
				if (r1.ligne[i].val[att1] < r1.ligne[i].val[att2])
				{
					for (j=0; j < r1.attsize; j++)
					{
						set(tmp, j, get(getNUPLET(r1, i), j));
					}
					insert(&res, tmp);
				}
			}
			break;
			
			//Operateur ">"
		case 2:
			for (i=0; i < r1.size; i++)
			{
				if (r1.ligne[i].val[att1] > r1.ligne[i].val[att2])
				{
					for (j=0; j < r1.attsize; j++)
					{
						set(tmp, j, get(getNUPLET(r1, i), j));
					}
					insert(&res, tmp);
				}
			}
			break;
			
			//Operateur "!="
		case 3:
			for (i=0; i < r1.size; i++)
			{
				if (r1.ligne[i].val[att1] != r1.ligne[i].val[att2])
				{
					for (j=0; j < r1.attsize; j++)
					{
						set(tmp, j, get(getNUPLET(r1, i), j));
					}
					insert(&res, tmp);
				}
			}
			break;
			
		default:
			//Si ce n'est pas un operateur alors la RELATION sera VIDE (taille = 0)
			break;
	}
	
	return res;
}

//SELECT attributs FROM r1;
RELATION OpProjection(RELATION r1, int* attributs, int taille)
{
	int i;
	int j;
	RELATION res = newRELATION(taille, r1.sizemax);
	NUPLET tmp = newNUPLET(taille);
	for (i=0; i < r1.size; i++)
	{
		for (j=0; j < taille; j++)
		{
			set(tmp, j, get(getNUPLET(r1, i), attributs[j]));
		}
		insert(&res, tmp);
	}
	return res;
}

//SELECT * FROM r1,r2;
RELATION OpProduitCartesien(RELATION r1, RELATION r2)
{
	int i;
	int j;
	int k;
	int l;
	RELATION res = newRELATION((r1.attsize + r2.attsize), (r1.size*r2.size));
	NUPLET tmp = newNUPLET(r1.attsize + r2.attsize);
	
	for (i=0; i < r2.size; i++)
	{
		for (k=0; k < r2.attsize; k++)
		{
			//On set les attributs de la relation r2
			set(tmp, k + r1.attsize, get(getNUPLET(r2, i), k));
		}
		for (j=0; j < r1.size; j++)
		{
			//Pour tous les élements de la relation r1
			for (l=0; l < r1.attsize; l++)
			{
				//on set les attibuts de la relation r1
				set(tmp, l, get(getNUPLET(r1, j), l));
			}
			insert(&res, tmp);
		}
	}
	return res;
}

// SELECT * FROM r1, r2 WHERE r1.attr1 = r2.attr2;
RELATION OpJointure(RELATION r1, RELATION r2, int attr1, int attr2)
{
	int i;
	int j;
	int k;
	int maxsize = (r1.sizemax > r2.sizemax) ? r1.sizemax : r2.sizemax;
	RELATION res = newRELATION((r1.attsize + r2.attsize - 1), maxsize);
	NUPLET tmp = newNUPLET(r1.attsize + r2.attsize - 1);
	
	for (i=0; i < r1.size; i++)
	{
		for (j=0; j < r2.size; j++)
		{
			if (r1.ligne[i].val[attr1] == r2.ligne[j].val[attr2])
			{
				for (k=0; k < r1.attsize; k++)
				{
					set(tmp, k, r1.ligne[i].val[k]);
				}
				for (k=0; k < r2.attsize; k++)
				{
					if (k != attr2)
					{
						set(tmp, k + r1.attsize, r2.ligne[j].val[k]);
					}
				}
				insert(&res, tmp);
			}
		}
	}
	return res;
}

















