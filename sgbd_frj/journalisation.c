//
//  journalisation.c
//  sgbd_frj
//
//  Created by Flavien Ronteix--jacquet on 13/01/2018.
//  Copyright © 2018 frj. All rights reserved.
//

#include "journalisation.h"

JOURNAL openLog(const char* path)
{
	JOURNAL tmp;
	if ((tmp.fp = fopen(path, "a+")) == NULL) //On peut que ajouter du texte mais on peut lire tout le fichier
	{
		tmp.path = "";
		tmp.state = 0;
		return tmp;
	}
	strcpy(tmp.path, path);
	tmp.state = 1;
	return tmp;
}

int logNewCommand(JOURNAL* log, const char* command)
{
	if (log->state == 0)
	{
		return -1;
	}
	fputs(command, log->fp);
	return 1;
}

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
