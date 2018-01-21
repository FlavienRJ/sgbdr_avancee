//
//  journalisation.h
//  sgbd_frj
//
//  Created by Flavien Ronteix--jacquet on 13/01/2018.
//  Copyright © 2018 frj. All rights reserved.
//

#ifndef journalisation_h
#define journalisation_h

#include <stdio.h>
#include <stdlib.h>
#include "sgbd.h"

/** 
 * @brief  Création et ouverture d'un journal
 * @note   
 * @param  path: le chemin vers le fichier journal
 * @retval un journal
 */
JOURNAL openLog(const char* path);

/** 
 * @brief  Ecriture dans le fichier journal d'une nouvelle commande
 * @note   
 * @param  log: le journal
 * @param  command: la commande à log
 * @retval 
 */
int logNewCommand(JOURNAL* log, const char* command);

/** 
 * @brief  Fermeture du journal
 * @note   
 * @param  log: 
 * @retval 
 */
int closeLog(JOURNAL log);

#endif /* journalisation_h */
