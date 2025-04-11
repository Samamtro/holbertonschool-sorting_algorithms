Projet : C - Sorting algorithms & Big O

Task 1-insertion_sort_list.c, 1-O

Ce code implémente l'algorithme de tri par insertion sur une liste doublement
chainée. il réorganise les elements pour les trier en ordre croissant en
déplaçant chaque élément à sa position correcte dans la liste triée. Le code
utilise des pointeurs pour naviguer dans la liste et effectuer les

void insertion_sort_list(listint_t **list)
listint_t **list : Un pointeur vers un pointeur de la tête de la liste
Retourne : Rien (void function).
Rôle : Trie la liste en place (pas besoin de retourner une nouvelle liste).

🚀 Déroulement du tri
1️⃣ Vérification des cas de base

if (list == NULL || *list == NULL)
{
    return;

Pourquoi ?
Si list est NULL (pointeur inexistant) ou si *list est NULL (liste vide), alors
il n’y a rien à trier.
On sort immédiatement de la fonction.

2️⃣ Initialisation du pointeur courant

current = (*list)->next;
Pourquoi ?
On commence à trier à partir du deuxième élément de la liste (current).
On initialise current sur le deuxième élément de la liste (le premier est déjà
considéré comme trié)

3️⃣ Boucle principale

while (current != NULL)
{
    temp = current;
    next = current->next;

while: boucle principale
current : Pointeur vers l'élément courant de la liste.
temp : L'élément qu'on va insérer au bon endroit.
next : Sauvegarde du prochain élément à traiter.
Pourquoi ?
On va déplacer temp dans la liste triée jusqu'à ce qu'il soit à sa place.

4️⃣ Déplacement de temp

temp->prev->next = temp->next;
if (temp->next != NULL)
    temp->next->prev = temp->prev;

Explication: On retire temp de sa position actuelle en modifiant les liens :
- Le prédécesseur de temp (temp->prev) doit pointer vers le suivant de temp
  (temp->next).
- Si temp n'est pas le dernier élément, on met à jour le prédécesseur de
  temp->next.
- On met à jour le lien avant de temp pour qu'il pointe vers son prédécesseur
  (temp->prev).
- On met à jour le lien arrière de temp->next pour qu'il pointe vers temp.

6️⃣ Insertion de temp à sa nouvelle position

temp->next = temp->prev;
temp->prev = temp->prev->prev;
temp->next->prev = temp;

Explication: On insère temp avant son prédécesseur :
- On met à jour le lien avant de temp pour qu'il pointe vers son prédécesseur
  (temp->prev).
- On met à jour le lien arrière de temp->next pour qu'il pointe vers temp.
- Si temp->prev n'est pas NULL, on met à jour le lien avant de temp->prev pour
  qu'il pointe vers temp.
- Sinon, on met à jour la tête de la liste pour qu'elle pointe vers temp.
- On affiche la liste après chaque insertion pour visualiser le tri.

7️⃣ Mise à jour de la tête de liste

if (temp->prev != NULL)
    temp->prev->next = temp;
else
    *list = temp;
Pourquoi ?
- Si temp->prev n'est pas NULL, cela signifie que temp n'est pas le premier
  élément de la liste. On met à jour le lien avant de temp->prev pour qu'il
  pointe vers temp.
- Sinon, on met à jour la tête de la liste pour qu'elle pointe vers temp.
- On affiche la liste après chaque insertion pour visualiser le tri.
-
8️⃣ Passage à l'élément suivant

current = next;
Pourquoi ?
- On passe à l'élément suivant dans la liste pour continuer le tri.
- On répète le processus jusqu'à ce que tous les éléments soient triés.
- On continue jusqu'à ce que current soit NULL, ce qui signifie que tous les
  éléments ont été traités.


1-O
O(n)
O(n^2)
O(n^2)

Les notations O(n), O(n²), O(log n) sont issues de la notation Big-O, qui permet
de décrire la complexité algorithmique d'un algorithme en fonction de la taille
d'un tableau. La notation Big-O donne une idée de la vitesse d'exécution
d'un algorithme en fonction de la taille de l'entrée. Elle est utilisée pour
analyser la performance d'un algorithme et pour comparer différents
algorithmes entre eux.

O(n²) – Complexité Quadratique
Def - La complexité quadratique O(n²) signifie que le temps d'exécution de
l'algorithme augmente proportionnellement au carré de la taille de
l'entrée.
Exemple:
🔹 Si n = 10, environ 100 opérations.
🔹 Si n = 1 000, environ 1 000 000 opérations.
Le temps explose lorsque n grandit.

O(n²) – Complexité Quadratique
Def - La complexité quadratique O(n²) est souvent associée à des algorithmes
de tri simples, comme le tri à bulles, le tri par insertion ou le tri
par sélection.
- Ces algorithmes effectuent des comparaisons et des échanges entre
paires d'éléments adjacents, ce qui entraîne un nombre d'opérations
proportionnel au carré de la taille du tableau.
- Par exemple:
🔹 Si n = 10, il y a 10 opérations.
🔹 Si n = 1 000 000, il y a 1 000 000 opérations.
Le temps de calcul double si n double

