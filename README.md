# F202

Réalisation d'un projet jeu vidéo ***sokoban***.

---

## Sokoban
>    Jeu dans lequel on contrôle un personnage se déplaçant sur des cases carrées, le but est de pousser ces boîtes sur des cases cibles.
>*(voir ci_dessous)*

![](/src/images/220px-Sokoban_ani.gif)

---
### Tâches de base

- [ ] un personnage contrôlé au clavier qui peut se déplacer dans 4 direction sur un plateau de cases
- [ ] des murs infranchissables
- [ ] des éléments (boîtes dans le jeu original) que le personnage peut pousser
- [ ] des cases cibles sur lesquels le joueur doit mettre les boîtes
- [ ] un moyen de réinitialiser le niveau, que ce soit un bouton à cliquer ou une touche du clavier

### Tâches supplémentaires

- [ ] **Animation des éléments en cours de déplacement.** Lorsque le personnage ou les
boîtes se déplacent, animez ce déplacement (c’est à dire que les éléments ne se déplacent
plus instantanément d’une case à la suivante mais “glissent” entre les deux)
- [ ] **Cases de téléportation.** Ajoutez des cases qui, lorsque le personnage se place dessus, l’envoient vers une autre case correspondantes (et dans l’autre sens également) si
aucune boîte ne la couvre
- [ ] **Boites de couleur.** Ajoutez des boîtes et des cases cibles colorées, de manière à ce que
le niveau ne soit résolu que lorsque les boites de couleurs sont sur des cibles de la même
couleur
- [ ] **Boîtes légères.** Ajoutez des boîtes légères. Le joueur doit pouvoir pousser plusieurs
boîtes légères en même temps si elles se trouvent l’une derrière l’autre.
- [ ] **Compteur de pas.** Ajoutez un élément sur l’écran, qui indique au joueur combien de
pas il a effectué jusqu’à présent sur le niveau.
- [ ] **Meilleur score de pas.** Affichez quelque part le score de pas le plus bas obtenu par le
joueur pour chaque niveau. Ce score doit être enregistré et persister à la fermeture du
programme. Il faut aussi pouvoir le réinitialiser.
- [ ] **Écran d’accueil.** Lorsque vous démarrez le jeu, un écran d’accueil apparaît pendant
une seconde avant que l’écran principal du jeu ne s’affiche. L’écran d’accueil doit inclure
votre nom.
- [ ] **Niveaux et sélection de niveau.** Implémentez différents niveaux que vous enregistrez
dans un ou plusieurs fichiers. Vous devez y retenir l’emplacement des murs, des différents élements du jeu implémentés (boîtes colorées ou non, teleporteurs, cibles) et la position de départ du joueur. Il vous faut ensuite un écran de sélection de niveau et un moyen d’y accéder depuis le menu principal. L’écran de sélection de niveau peut être simple.
- [ ] **Limite de pas.** Ajoutez une limite de pas maximum sur certains niveaux (cette tâche
nécessite donc d’avoir fait plusieurs niveaux). Une victoire ne doit être déclenchée que
si le joueur a gagné avec au plus le maximum de pas demandé, sinon une défaite est
affichée. Le nombre de pas restants doit être affiché.
- [ ] **Déplacement automatique à la souris.** Ajoutez la possibilité de cliquer sur une case
à la souris pour que le personnage se déplace vers cette case s’il y a un chemin pour y
parvenir sans déplacer de boites.
- [ ] **Éditeur de niveau.** Ajoutez la possibilité de pouvoir modifier un niveau de manière
interactive au lieu d’y jouer. Vous devriez pouvoir enregistrer les modifications et ajouter
de nouveaux niveaux.
- [ ] **Détection d’échec.** Une boîte qui se trouve dans un coin formé par des murs est bloquée : le joueur ne peut plus la déplacer. Une boîte qui se trouve dans un coin formé par
des boîtes bloquées et/ou des murs et aussi bloquée. Si toutes les boîtes sont bloquées
alors un message d’échec apparaît avec un bouton pour recommencer la partie.
