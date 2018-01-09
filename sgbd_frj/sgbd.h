/*
 * CORE HEADER
 *
 */

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/** 
 * @brief 
 * @val : tableau de valeur
 * @size : la taille du NUPLET
 */
typedef struct nuplet
{
	int* 		val;
	int 		size;
	
} NUPLET;

/** 
 * @brief
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
 * @brief  Liste des operateurs autorisés
 */
typedef enum operateur
{
	UNION, INTERSECT, WHERE, SELECT, PRODUCT, JOIN
	
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
	char*		argc;
	int			argv;
	
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
	NUPLET** 	data;
	int 		nbtable;
	int* 		sizetable;
	int			state;
	
} BDD;

