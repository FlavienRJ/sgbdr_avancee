# Documentation de mon SGBD
## Cours de SGBD avancée M. Nguyen INSA
### Ronteix--Jacquet Flavien

## choses à implémenter
### D'après le cours
- Création de transaction :
- Execution de transaction :
- 1 seule transactio à la fois dans un premier temps donc pas besoin de tester la seriabilisabilité
- On peut faire de l'estampillage
- Verrouillage avec S et X sur les Nuplets
- Indexation sur le fichier
- Arbre-B pour la gestion des données
- Flemme de faire du hashage
- Parser de requête SQL
- Equivalence avec un plan d'execution logique
- Conversion en plan d'execution physique
- Optimisation, c'est trop compliqué
- Operateur en mode naïf, à convertir en mode pipelinage
- Faire du tri dans la table (order by)
- Jointure par hachage plutot que jointure naturelle
- Modele de controle d'acces DAC entre des utilisateurs et des objets
- Different niveau d'utilisateur, MAC multiniveau
- Connexion utilisateur... faire au plus simple avec un fichier id/mdp
- Ajouter un fichier journal pour le log des opérations sur la bdd avec enregistrement systematique

### D'après le TP
- fonction OpUnion : OK
- fonction operateur restriction : OK
- fonction operateur produit cartésien : OK
- different operateur de jointure HashJoin et SortMergeJoin :
- Parser de requete de l'algebre relationnelle :
- Fonction fullscan : OK
- Insert, delete update dans une table : OK
- Optimiser les accès disque avec un index sur la table
- Transaction et optimisation



## Fonctionnement general du programme
### Demonstration
### Fichiers
**main.c**

**parsing**

**operateur**

**controle_acces**

**iohelper**

**nuplet_helper**

**relation helper**

## Regles d'utilisation
### le langage

