#include "iohelper.h"

/** 
 * @brief  Initialise une BDD
 * @note   
 * @retval un pointeur sur une BDD
 */
BDD* newBDD(void)
{
	BDD* res = (BDD*)malloc(sizeof(BDD));
	res->nbtable = 0;
	res->data = NULL;
	res->state = 0;
	res->sizetable = NULL;
	return res;
}

/** 
 * @brief  Importe les valeurs d'un fichier dans une table 
 * @note   Mapping de toutes une bdd en memoire vive
 * @param  parPath: le chemin vers le fichier
 * @param  parName: le nom de la table ouverte
 * @param  parBdd: pointeur vers une BDD
 * @retval -1 si erreur
 */
int openTable(char* parPath, char* parName, BDD* parBdd)
{
	//On ouvre le fichier
	FILE * fp;
	if ((fp = fopen(parPath, "w+")) == NULL)
	{
		return -1;
	}
	parBdd->path[parBdd->nbtable] = parPath;
	parBdd->noms[parBdd->nbtable] = parName;
	
	parBdd->state = 1;
	
	char *row = "";
	int i = 0;
	int j = 0;
	int ret;
	char* tok;
	long len_nuplet = 0; //nombre de colonne du nuplet
	long nb_nuplet = 0; //nombre de ligne du nuplet
	
	//On lit la taille du nuplet sur la premiere ligne de la bdd
	fscanf (fp,"%s ",row);
	tok = strsep(&row, ";");
	len_nuplet = tok - "0";
	tok = strsep(&row, ";");
	nb_nuplet = tok - "0";
	
	parBdd->data[parBdd->nbtable] = malloc(nb_nuplet*sizeof(NUPLET));
	//On lit toutes les lignes du fichier que l'on stocke dans des nuplets

	//Pour toutes les lignes
	while ((ret = fscanf (fp,"%s ",row)) != EOF && ret != 0)
	{
		parBdd->data[parBdd->nbtable][i] = newNUPLET((int)len_nuplet);
		j = 0;
		//Pour toutes les colonnes
		while ((tok = strsep(&row, ";")))
		{
			set(parBdd->data[parBdd->nbtable][i], j, (int)(tok - "0"));
			j++;
		}
		i++;
		//printf("%s", row);
	}
	parBdd->sizetable[parBdd->nbtable] = i;
	parBdd->nbtable++;
	
	fclose(fp);
	return 0;
}

/** 
 * @brief  Sauvegarde d'une BDD entiere (avec toutes les tables) dans des fichiers et fermeture
 * @note   
 * @param  parBDD: la BDD à fermer
 * @retval -1 si erreur
 */
int closeBDD(BDD* parBDD)
{
	FILE * fp;
	int i;
	int j;
	int k;
	
	for (i=0; i < parBDD->nbtable; i++) //Pour le nombre de table
	{
		if ((fp = fopen(parBDD->path[i], "w+")) == NULL)
		{
			return -1;
		}
		fprintf(fp, "\n");
		for (j=0; j < parBDD->sizetable[i]; j++) //Pour le nombre de ligne
		{
			for (k=0; k < parBDD->data[i][j].size; k++) //Pour le nombre de colonne
			{
				fprintf(fp, "%d;", get(parBDD->data[i][j],k));
			}
			fprintf(fp, "\n");
		}
		fseek(fp, 0, SEEK_SET); //verifier si ca fai tun append ou un insert
		fprintf(fp, "%d;%d;",parBDD->data[i][j].size,j);
		fclose(fp);
	}
	free(parBDD);
	return 0;
}

/** 
 * @brief  Sauvegarde d'un NUPLET dans une table de la bdd
 * @note   
 * @param  parBdd: la BDD
 * @param  parTable: le nom de la table
 * @param  parPos: la position dans la table
 * @param  parVal: le NUPLET à stocker
 * @retval -1 si erreur
 */
int store(BDD* parBdd, const char* parTable, int parPos, NUPLET parVal)
{
	int i;
	int j;
	
	if ((i = tableDansBdd(*parBdd, parTable)) < 0)
	{
		return -1;
	}
	//On realloue la taille de data pour la table
	parBdd->data[i] = realloc(parBdd->data[i], (parBdd->sizetable[i] + 1));
	if (parBdd->data[i] == NULL)
	{
		return -1;
	}
	parBdd->sizetable[i]++;
	//On decale tous les elements apres parPos vers la fin de la table
	for (j = parBdd->sizetable[i]; j > parPos; j--)
	{
		//On copie i-1 dans i
		copy(parBdd->data[i][j-1], &parBdd->data[i][j]);
	}
	// La valeur de parVal est mis dans data[parPos], attention a verifier la compatibilite
	parBdd->data[i][parPos] = parVal;
	
	return 0;
}

/** 
 * @brief  recuperation d'un nuplet dans une BDD
 * @note   
 * @param  parBdd: la BDD
 * @param  parTable: le nom de la table
 * @param  parPos: la position du NUPLET
 * @retval le NUPLET
 */
NUPLET getNupletBdd(BDD parBdd, const char* parTable, int parPos)
{
	int i;
	if ((i = tableDansBdd(parBdd, parTable)) < 0)
	{
		return newErrNUPLET();
	}
	
	NUPLET res = newNUPLET(parBdd.data[i][parPos].size);
	copy(parBdd.data[i][parPos], &res);
	return res;
}

/** 
 * @brief  retourne la taille d'une table de la BDD
 * @note   
 * @param  parBdd: la BDD
 * @param  parTable: le nom de la table
 * @retval la taille de la table
 */
int size(BDD parBdd, const char* parTable)
{
	int i;
	if ((i = tableDansBdd(parBdd, parTable)) < 0)
	{
		return -1;
	}
	return parBdd.sizetable[i]; //renvoie le nombre de NUPLET dans une table
}

/** 
 * @brief  verifie si une table existe dans la BDD
 * @note   
 * @param  parBdd: la BDD
 * @param  parTable: le nom de la table
 * @retval l'index de la table dans la BDD si elle existe
 */
int tableDansBdd(const BDD parBdd, const char* parTable)
{
	int i;
	for (i=0; i < parBdd.nbtable; i++)
	{
		if ((strcmp(parTable, parBdd.noms[i]))==0)
		{
			return i;
		}
	}
	return -1;
}

/** 
 * @brief  Affichage d'une table dans la console
 * @note   
 * @param  parBdd: la BDD
 * @param  parTable: le nom de la table
 * @retval None
 */
void printTable(const BDD parBdd, const char* parTable)
{
	int i = tableDansBdd(parBdd, parTable);
	if (i < 0)
	{
		printf("La table %s n'existe pas dans la bdd\n", parTable);
	}
	int j;
	printf("Table %s a %d elements : \n", parTable, parBdd.sizetable[i]);
	for (j = 0; j < parBdd.sizetable[i]; i++)
	{
		afficheNUPLET(parBdd.data[i][j]);
	}
}














