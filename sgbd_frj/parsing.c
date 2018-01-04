#include "parsing.h"

int getInput(char** raw)
{
	char tmp[512];
	int semicolon[10];
	int i = 0;
	int j = 0;
	int k;
	
	printf("Tapez la requête, elle doit se terminer par \";\" \n");
	gets(tmp);
	
	while (i < 256 || strcmp(&tmp[i], "\0") != 0)
	{
		if (strcmp(&tmp[i], ";") == 0)
		{
			semicolon[j] = i;
			j++;
		}
		i++;
	}
	for (k=0; k < j - 1; k++)
	{
		strncpy(raw[k], &tmp[k], (semicolon[k+1]-semicolon[k]));
	}
	return k;
}

int parseInput(char*** rawToken, char** raw, int taille)
{
	int i;
	const char s[2] = " ";
	
	for (i=0; i < taille; i++)
	{
		*rawToken[i] = strtok(raw[i], s);
	}
	
	return 0;
}

int getCommand(char*** rawToken, REQUETE* listeOperation, int nbRequete)
{
	int i;
	
	for (i=0; i < nbRequete; i++)
	{
		//BESOIN DE DETERMINER LES INSTRUCTIONS DE MON LANGAGE
	}
	return 0;
}
