/*
 * OPERATEURS SGBD
 */

#ifndef operateurs_h
#define operateurs_h

#include <stdio.h>
#include "sgbd.h"
#include "nuplet_helper.h"
#include "relation_helper.h"

/** 
 * @brief  operation d'UNION OK
 * @note  SELECT * FROM r1 UNION SELECT * FROM r2; 
 * @param  r1: 
 * @param  r2: 
 * @retval 
 */
RELATION OpUnion(RELATION r1, RELATION r2);

/** 
 * @brief  operation Intersection PRESQUE
 * @note   SELECT * FROM r1 INTERSECT SELECT * FROM r2;
 * @param  r1: 
 * @param  r2: 
 * @retval 
 */
RELATION OpInter(RELATION r1, RELATION r2);

/** 
 * @brief  Operateur de Restriction pour une valeur fixe OK
 * @note   SELECT * FROM r1 WHERE r1.att operateur(<,=,...) valeur
 * @param  r1: 
 * @param  att: 
 * @param  operateur: 0 = "==", 1 = "<", 2 = ">", 3 = "!="
 * @param  valeur: 
 * @retval 
 */
RELATION OpRestrictionCST(RELATION r1, int att, int operateur, int valeur); // operateur : 0 : == ; 1 : < ; 2 : >

/** 
 * @brief  Operateur de Restriction pour une valeur variable OK
 * @note   SELECT * FROM r1 WHERE r1.att operateur(<,=,...) r1.att2
 * @param  r1: 
 * @param  att1: 
 * @param  operateur: 0 = "==", 1 = "<", 2 = ">", 3 = "!="
 * @param  att2: 
 * @retval 
 */
RELATION OpRestrictionATT(RELATION r1, int att1, int operateur, int att2);  // idem ici

/** 
 * @brief  Operateur de projection OK
 * @note   SELECT attributs FROM r1;
 * @param  r1: 
 * @param  attributs: 
 * @param  taille: 
 * @retval 
 */
RELATION OpProjection(RELATION r1, int* attbuributs, int taille);

/** 
 * @brief  Operateur de produit cartesien OK
 * @note   SELECT * FROM r1,r2;
 * @param  r1: 
 * @param  r2: 
 * @retval 
 */
RELATION OpProduitCartesien(RELATION r1, RELATION r2);

/** 
 * @brief  Operateur de jointure entre 2 relations PRESQUE
 * @note   SELECT * FROM r1, r2 WHERE r1.attr1 = r2.attr2;
 * @param  r1: 
 * @param  r2: 
 * @param  attr1: 
 * @param  attr2: 
 * @retval 
 */
RELATION OpJointure(RELATION r1, RELATION r2, int attr1, int attr2);

/** 
 * @brief  Operateur de Jointure Hash Join
 * @note   
 * @param  r1: 
 * @param  r2: 
 * @param  attr1: 
 * @param  attr2: 
 * @retval 
 */
RELATION OpJointureHash(RELATION r1, RELATION r2, int attr1, int attr2);

/** 
 * @brief  Operateur de jointure par Sort Merge
 * @note   
 * @param  r1: 
 * @param  r2: 
 * @param  attr1: 
 * @param  attr2: 
 * @retval 
 */
RELATION OpJointureSortMerge(RELATION r1, RELATION r2, int attr1, int attr2);


/** 
 * @brief  Calcul d'un hash pour une clef
 * @note   Methode la plus simple avec le modulo
 * @param  clef: 
 * @retval 
 */
int hashCode(const int clef);

/** 
 * @brief  Ajouter un NUPLET à une table de Hash par méthode la liste chainée
 * @note   
 * @param  hash_table: la table de Hash
 * @param  clef: la clef (calculé avec hashCode)
 * @param  data: la NUPLET
 * @retval None
 */
void insertHash(TABLE_HASH* hash_table, int clef, NUPLET data);

/** 
 * @brief  Tri par insertionSort d'une relation
 * @note   
 * @param  r: la Relation à trier
 * @param  attr: l'attribut sur lequel trier
 * @retval une Relation trié
 */
RELATION insertionSort(RELATION r, int attr);

/**
 * @brief  Tri par bubbleSort d'une relation
 * @note
 * @param  r: la Relation à trier
 * @param  attr: l'attribut sur lequel trier
 * @retval une Relation trié
 */
RELATION bubbleSortR(RELATION r, int attr);

#endif

