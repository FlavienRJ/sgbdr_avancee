/*
 * CORE HEADER
 */

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/** 
 * @brief  Les CONSTANTES
 */
#define TAILLE_MAX_CHAINE 256
#define TAILLE_HASH 20
#define TAILLE_BUCKET 256

/** 
 * @brief le NUPLET
 * @val : tableau de valeur
 * @size : la taille du NUPLET
 */
typedef struct nuplet
{
	int* 		val;
	int 		size;
	
} NUPLET;

/** 
 * @brief  le NUPLET indexé
 * @index : l'index
 * @val : tableau de valeur
 * @size : la taille du NUPLET
 */
typedef struct nuplet_index
{
	int 		index;
	int* 		val;
	int 		size;

} NUPLET_INDEX;

/** 
 * @brief la RELATION
 * @ligne : un tableau de NUPLET, lignes  
 * @attsize : le nombre de colonne de la table
 * @size : le nombre de ligne
 * @sizemax : le nombre maximum de ligne autorisé
 */
typedef struct relation
{
	NUPLET* 	ligne;
	int 		attsize;
	int 		size;
	int 		sizemax;
	
} RELATION;

/** 
 * @brief
 * @ligne : un tableau de NUPLET_INDEX, lignes  
 * @attsize : le nombre de colonne de la table
 * @size : le nombre de ligne
 * @sizemax : le nombre maximum de ligne autorisé
 */
typedef struct relation_index
{

	NUPLET_INDEX* 	ligne;
	int 			attsize;
	int 			size;
	int 			sizemax;

} RELATION_INDEX;

/** 
 * @brief  Liste des operateurs autorisés
 */
typedef enum operateur
{
	FROM, UNION, INTERSECT, WHERE, SELECT, PRODUCT, JOIN
	
} OPERATEUR;

/** 
 * @brief  
 * @op : l'operateur qui intervient dans l'operation
 * @argc : liste des arguments de l'operation
 * @argv : le nombre d'argument
 */
typedef struct operation
{
	OPERATEUR 	op;
	char**		argv;
	int			argc;
	
} OPERATION;

/** 
 * @brief A REPRESENTER SOUS FORME D'ARBRE ET NON DE TABLEAU
 * @operations : la liste des operations de la requete
 * @taille : le nombre d'operation à réaliser
 */
typedef struct requete
{
	OPERATION* 	operations;
	int 		taille;
	
} REQUETE;

/** 
 * @brief representation d'une base de donnee en memoire
 * @path : la liste des chemins vers les fichiers de table
 * @noms : la liste des noms de tables
 * @data : tableu de 2 dimensions de NUPLET : A MODIFIER AVEC DES RELATIONS PLUTOT
 * @nbtable : nombre de table dans la BDD
 * @sizetable : la liste des tailles des tables
 * @state : l'etat de la BDD, 0 = uninitialized, 1 = not read, 2= ready
 */
typedef struct bdd
{
	char** 		path;
	char** 		noms;
	RELATION* 	data;
	int 		nbtable;
	int* 		sizetable;
	int			state;
	
} BDD;

/** 
 * @brief  un element de la liste chainé pour la table de hash
 */
typedef struct item_hash
{
	int clef;
	NUPLET data;
	struct item_hash* next;

} ITEM_HASH;

/** 
 * @brief  La table de hash
 */
typedef struct table_hash
{
	struct item_hash* 	table[TAILLE_HASH];
	int				size_table[TAILLE_HASH];
} TABLE_HASH;

/** 
 * @brief  le journal
 */
typedef struct journal
{
	FILE* 	fp;
	char* 	path;
	int		state; //0 = erreur à la lecture, 1= ouverture du fichier reussi

} JOURNAL;



