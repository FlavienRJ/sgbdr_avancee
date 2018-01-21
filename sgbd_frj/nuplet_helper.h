#ifndef nuplet_helper_h
#define nuplet_helper_h

#include <stdio.h>
#include <stdlib.h>

#include "sgbd.h"

/** 
 * @brief  Création d'un NUPLET
 * @note   
 * @param  size: nb d'attribut
 * @retval retourne un NUPLET
 */
NUPLET newNUPLET(int size);

/** 
 * @brief  Ecriture d'un attribut d"un NUPLET
 * @note   
 * @param  n: le NUPLET
 * @param  col: l'attribut
 * @param  val: la nouvelle valeur de l'attribut
 * @retval None
 */
void set(NUPLET n, int col, int val);

/** 
 * @brief Lecture d'un attribut d'un NUPLET 
 * @note   
 * @param  n: le NUPLET	
 * @param  col: l'attribut à lire
 * @retval 
 */
int get(NUPLET n, int col);

/** 
 * @brief  Copie d'un NUPLET vers un autre
 * @note   
 * @param  org: le NUPLET source	
 * @param  cpy: le NUPLET destination
 * @retval None
 */
void copy(const NUPLET org, NUPLET* cpy);

/** 
 * @brief  Création d'un NUPLET d'erreur pour la gestion des erreurs
 * @note   
 * @retval 
 */
NUPLET newErrNUPLET(void);

/** 
 * @brief  Cherche un NUPLET dans une relation
 * @note   
 * @param  r: la relation
 * @param  att: un tableau d'attribut pour trouver un NUPLET
 * @retval la position si le NUPLET existe, -1 sinon
 */
int findNuplet(const RELATION r, const int* att);

/** 
 * @brief  Affichage d'un NUPLE
 * @note   
 * @param  n: le NUPLET
 * @retval None
 */
void afficheNUPLET(NUPLET n);

#endif
