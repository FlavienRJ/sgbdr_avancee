#ifndef parser_h
#define parser_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <regex.h>
#include <stdio.h>
#include <ctype.h>

#include "sgbd.h"
#include "operateurs.h"
#include "nuplet_helper.h"
#include "relation_helper.h"
#include "iohelper.h"
#include "journalisation.h"

/** 
 * @brief Delete every character that is not a letter or a number
 * @note   
 * @param  src: The string to filter
 * @retval None
 */
void filterParser(char* src);

/** 
 * @brief Return a relation from a number
 * @note   
 * @param  s: The relation number
 * @param  bdd: The bdd structure
 * @retval 
 */
RELATION stR(char* s, BDD* bdd);

/** 
 * @brief Detect what kind of arguments there is and makes the related operations. Is a bit capricious still.
 * @note   
 * @param  argc: Regular argc
 * @param  **argv: Regular arv
 * @param  bdd: The bdd structure
 * @param  log: The log structure 
 * @retval 
 */
RELATION parser(int argc, char **argv, BDD* bdd, JOURNAL* log);



#endif /* parser_h */

