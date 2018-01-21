# Documentation du SGBD
## Cours de SGBD avancée M. Nguyen INSA
### Ronteix--Jacquet Flavien
### Bertuglia Camille

## choses à implémenter
### D'après le cours
- Création de transaction :
- Execution de transaction :
- 1 seule transactio à la fois dans un premier temps donc pas besoin de tester la seriabilisabilité
- On peut faire de l'estampillage
- Verrouillage avec S et X sur les Nuplets : Camille
- Indexation sur le fichier : En cours
- Arbre-B pour la gestion des données
- Flemme de faire du hashage
- Parser de requête SQL
- Equivalence avec un plan d'execution logique
- Conversion en plan d'execution physique
- Optimisation, c'est trop compliqué
- Operateur en mode naïf, à convertir en mode pipelinage
- Faire du tri dans la table (order by) : En cours
- Jointure par hachage plutot que jointure naturelle
- Modele de controle d'acces DAC entre des utilisateurs et des objets
- Different niveau d'utilisateur, MAC multiniveau
- Connexion utilisateur... faire au plus simple avec un fichier id/mdp
- Ajouter un fichier journal pour le log des opérations sur la bdd avec enregistrement systematique

### D'après le TP
- Opérateurs: OK Flavien
- Parser de requete de l'algebre relationnelle : OK Camille
- Fonction fullscan : OK Flavien
- Insert, delete update dans une table : Pas parsé
- Indexation dans les tables et le fichier : En cours
- Optimiser les accès disque avec un index sur la table: X
- Transaction et optimisation: X
- Journalisation des requetes : OK Flavien

