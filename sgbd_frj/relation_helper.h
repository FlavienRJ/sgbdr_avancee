#ifndef relation_helper_h
#define relation_helper_h

#include <stdio.h>
#include "nuplet_helper.h"

/** 
 * @brief  Creation d'une nouvelle RELATION
 * @note   
 * @param  attsize: le nombre d'attribut
 * @param  maxsize: la taille maximale de la RELATION
 * @retval Une nouvelle RELATION
 */
RELATION newRELATION(int attsize, int maxsize);

/** 
 * @brief  Verifie la compatibilité entre une RELATION et un NUPLET
 * @note   
 * @param  r: la RELATION
 * @param  n: le NUPLET
 * @retval 1 si compatible, 0 sinon
 */
int compatible(RELATION r, NUPLET n);

/** 
 * @brief  Insertion d'un NUPLET dans une RELATION
 * @note   
 * @param  r: la RELATION
 * @param  n: le NUPLET à ajouter
 * @retval None
 */
void insert(RELATION* r, NUPLET n);

/** 
 * @brief  Insertion à une position d'un NUPLET dans une RELATION
 * @note   
 * @param  r: la RELATION
 * @param  n: le NUPLET à ajouter
 * @param  pos: la position
 * @retval None
 */
void insertPos(RELATION* r, NUPLET n, int pos);

/** 
 * @brief  Récupération d'un NUPLET dans une RELATION
 * @note   
 * @param  r: La RELATION
 * @param  ligne: La ligne
 * @retval le NUPLET dans la ligne dans la RELATION
 */
NUPLET getNUPLET(RELATION r, int ligne);
int findNuplet(const RELATION r, const int* att);

/** 
 * @brief  Affichage d'une RELATION
 * @note   
 * @param  r: la RELATION
 * @retval None
 */
void afficheRELATION(RELATION r);

/** 
 * @brief  Parcours les NUPLET d'une RELATION
 * @note   La position du NUPLET renvoyé est sauvegardé entre chaque appel de la fonction et reviens à 0 si le nom de la table est différent
 * @param  r: La RELATION
 * @param  name: Le nom de la RELATION
 * @retval Le prochain NUPLET
 */
NUPLET fullscanNext(const RELATION r, const char* name);

#endif
