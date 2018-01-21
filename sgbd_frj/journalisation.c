//
//  journalisation.c
//  sgbd_frj
//
//  Gestion de l'ecriture de Log dans un fichier
//

#include "journalisation.h"

/** 
 * @brief  Création et ouverture d'un journal
 * @note   
 * @param  path: le chemin vers le fichier journal
 * @retval un journal
 */
JOURNAL openLog(const char* path)
{
	JOURNAL tmp;
    tmp.fp = (FILE*) malloc(sizeof(FILE));
	if ((tmp.fp = fopen(path, "a+")) == NULL) //On peut que ajouter du texte mais on peut lire tout le fichier
	{
		tmp.path = "";
		tmp.state = 0;
		return tmp;
	}
	tmp.path = (char*) malloc(sizeof(char)*1024);
    strcpy(tmp.path,path);
	tmp.state = 1;
	return tmp;
}

/** 
 * @brief  Ecriture dans le fichier journal d'une nouvelle commande
 * @note   
 * @param  log: le journal
 * @param  command: la commande à log
 * @retval 
 */
int logNewCommand(JOURNAL* log, const char* command)
{
	if (log->state == 0)
	{
		return -1;
	}
	fputs(command, log->fp);
	return 1;
}

/** 
 * @brief  Fermeture du journal
 * @note   
 * @param  log: 
 * @retval 
 */
int closeLog(JOURNAL log)
{
	if (log.state == 0)
	{
		return -1;
	}
	if ((fclose(log.fp)) == 0)
	{
		log.state = 0;
		return 1;
	}
	return -1;
}
