# holbertonschool-sorting_algorithms
Welcome to C - Sorting algorithms &amp; Big O

2-DEFINITION.c
Projet : C - Sorting algorithms & Big O

Task 2-selection_sort.c, 2-O

Ce code implémente l'algorithme de tri par sélection (Selection Sort) pour trier
un tableau d'entiers en ordre croissant. Analysons-le en détail.

2. Définition de la fonction selection_sort

void selection_sort(int *array, size_t size)

Explication : void selection_sort

La fonction selection_sort est une fonction en langage C qui implémente
l'algorithme du tri par sélection pour trier un tableau d'entiers en ordre
croissant.

void : Indique que la fonction ne retourne aucune valeur.

selection_sort : Nom de la fonction.

int *array : Prend en paramètre un pointeur vers un tableau d'entiers.

size_t size : Prend en paramètre la taille du tableau (de type size_t, qui
représente un entier non signé).

Cas particuliers

if (array == NULL || size < 2)
    return;

Explication : Vérification des cas particuliers
La fonction vérifie d'abord si le tableau est NULL ou si sa taille est inférieure à 2.
Si l'une de ces conditions est vraie, la fonction retourne immédiatement sans
effectuer de tri. Cela évite d'essayer de trier un tableau vide ou un tableau
contenant moins de deux éléments, car il n'est pas nécessaire de trier un tableau
de taille 0 ou 1.

3. Algorithme du tri par sélection
Boucle principale (parcours du tableau)

for (i = 0; i < size - 1; i++)

Explication : Boucle principale

La boucle principale parcourt le tableau d'entiers. La variable i représente
l'index de l'élément actuel. La boucle s'arrête lorsque i atteint size - 1,
car l'élément à l'index size - 1 n'a pas besoin d'être trié (il est déjà à sa
place si tous les éléments précédents sont triés).

Recherche du minimum dans la partie non triée

int min_index = i;

Explication : Initialisation de min_index

La variable min_index est initialisée à l'index actuel i. Elle sera utilisée
pour suivre l'index de l'élément minimum trouvé dans la partie non triée du
tableau.
Et

for (j = i + 1; j < size; j++)
{
	if (array[j] < array[min_index])
		min_index = j;
}

Explication : Recherche du minimum

j parcourt les indices après i.
Si array[j] < array[min_index], cela signifie que l'on a trouvé un élément encore plus petit.
On met à jour min_index pour qu'il pointe vers cet élément plus petit.

Échange des valeurs si nécessaire

if (min_idx != i)
{
    temp = array[i];
    array[i] = array[min_idx];
    array[min_idx] = temp;

    print_array(array, size);
}

Explication : Échange des valeurs

Si min_index est différent de i, cela signifie que l'élément minimum trouvé
dans la partie non triée est différent de l'élément à l'index i. Dans ce cas,
on effectue un échange entre ces deux éléments. On utilise une variable
temp pour stocker temporairement la valeur de array[i], puis on effectue
l'échange. Après l'échange, on appelle la fonction print_array pour
afficher l'état actuel du tableau après chaque échange.
