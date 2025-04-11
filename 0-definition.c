projet C - Sorting algorithms & Big O

Task 0

L’algorithme consiste à comparer des paires d'éléments adjacents et à les
échanger s’ils sont dans le mauvais ordre. Ce processus est répété jusqu'à ce
que le tableau soit trié. Le tri à bulles est simple à comprendre et à
implémenter, mais il n'est pas très efficace pour les grands tableaux.

📌 Prototype et vérifications

1 - void bubble_sort(int *array, size_t size)
- int *array → Pointeur vers le tableau à trier.
- size_t size → Taille du tableau (type size_t pour garantir qu'il soit positif).

Vérification des cas particuliers :
- Si le tableau est NULL ou si sa taille est inférieure à 2, la fonction
  retourne immédiatement sans effectuer de tri.
- La fonction ne retourne rien (void).

if (array == NULL || size < 2)
	return;

🔹 Implémentation du tri à bulles

for (i = 0; i < size - 1; i++)
La boucle externe représente les passages successifs dans le tableau.
- La boucle interne compare les éléments adjacents et les échange si
  nécessaire.

  for (j = 0; j < size - i - 1; j++)
- La boucle interne compare les éléments adjacents et les échange si
  nécessaire.
- La condition j < size - i - 1 garantit que les éléments déjà triés à la
  fin du tableau ne sont pas comparés à chaque passage.

🔹 Échange des valeurs
if (array[j] > array[j + 1])
{
    temp = array[j];
    array[j] = array[j + 1];
    array[j + 1] = temp;
}
Si array[j] est plus grand que array[j+1], on échange les deux valeurs.
- On utilise une variable temporaire (temp) pour stocker la valeur de
  array[j] avant de faire l'échange.
- On met à jour array[j] avec la valeur de array[j+1] et vice versa.

🔹 Affichage du tableau après chaque échange

[print_array(array, size);]

- La fonction print_array est appelée après chaque échange pour afficher
  l'état actuel du tableau.
- Cela permet de visualiser le processus de tri en temps réel.
- La fonction print_array est définie dans le fichier sort.h et est
  responsable de l'affichage du tableau.
- Elle prend en entrée le tableau et sa taille, et affiche les éléments
  séparés par des espaces.


  0-O
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
- La complexité quadratique O(n²) signifie que le temps d'exécution de
  l'algorithme augmente proportionnellement au carré de la taille de
  l'entrée.
  🔹 Si n = 10, environ 100 opérations.
  🔹 Si n = 1 000, environ 1 000 000 opérations.
  Le temps explose lorsque n grandit.

  O(n²) – Complexité Quadratique
- La complexité quadratique O(n²) est souvent associée à des algorithmes
  de tri simples, comme le tri à bulles, le tri par insertion ou le tri
  par sélection.
- Ces algorithmes effectuent des comparaisons et des échanges entre
  paires d'éléments adjacents, ce qui entraîne un nombre d'opérations
  proportionnel au carré de la taille du tableau.
- Par exemple:
🔹 Si n = 10, il y a 10 opérations.
🔹 Si n = 1 000 000, il y a 1 000 000 opérations.
 Le temps de calcul double si n double
