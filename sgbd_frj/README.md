# Documentation du SGBD
## Cours de SGBD avancée M. Nguyen INSA
### Ronteix--Jacquet Flavien
### Bertuglia Camille

## Fontionalités implémentées
- Structure de la sgbd - Flavien
- Opérateurs: Fonctionnels - Flavien
- Fonction fullscan : Fonctionnel Flavien
- Insert, delete update dans une table : Non fontionnel
- Faire du tri dans la table (order by) : Non fonctionnel
- Jointure par hachage plutot que jointure naturelle : Fonctionnel - Flavien
- Verrouillage avec S et X sur les Nuplets : Non fonctionnel
- Indexation sur le fichier : Non fonctionnel - Flavien
- Parser de requête SQL : Sommaire mais fonctionnel - Camille
- Ajouter un fichier journal pour le log des opérations sur la bdd avec enregistrement systematique : Non-fonctionnel - Flavien - Debuggage partiel Camille
- Help - Camille
- Makefile - Camille
- Documentation - Flavion - Camille



## Fonctionnement general du programme
### Demonstration
./main
./main help
./main SELECT all FROM 0 WHERE 1, 0, 42;
./main SELECT all FROM 0, 3;
./main SELECT 0, 2 FROM 3;


## Regles d'utilisation
### le langage
- Appeler le numéro associé à une table ou une relation (pas de noms)
- Utiliser la règle suivant pour les opérateurs: 0 = '=', 1 = '<', 2 = '>', 3 = '!='
- Ne pas utiliser le charactère *
- Bien séparer les arguments par des espaces (virgules optionnelles)
