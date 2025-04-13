 Rappel : Le code implémente le tri rapide (Quick Sort)
Le tri rapide est un algorithme très efficace utilisé pour trier des tableaux.
C'est un des algorithmes les plus populaires dans les bibliothèques standardcar
il est rapide dans la majorité des cas.

✅ Fonction principale : quick_sort

1 - void quick_sort(int *array, size_t size)

Details de la fonction :
- Cette fonction implémente l'algorithme de tri rapide (Quick Sort) pour trier un tableau d'entiers.
- Elle prend en entrée un tableau d'entiers (array) et sa taille (size).

size_t pivot;
@size_t : type entier non signé
@pivot : variable pour stocker l'index du pivot

Rôle :
Trie un tableau d'entiers avec l’algorithme Quick Sort.
🧩 Détail ligne par ligne :

2 - if (!array || size < 2)
        return;

	- Vérifie si le tableau est vide ou si sa taille est inférieure à 2.
- Si c'est le cas, la fonction retourne immédiatement sans effectuer de tri.
- Cela évite de traiter des tableaux qui ne nécessitent pas de tri.

Si le tableau est vide ou a moins de 2 éléments, on ne fait rien.

3 - print_sort(array, size, 1);

@array : tableau d'entiers à trier
@size : taille du tableau
@init : 1 (indique que c'est l'initialisation du tableau)

	- Appelle la fonction print_sort pour afficher l'état initial du tableau avant le tri.
	- Le troisième argument (1) indique que c'est l'initialisation du tableau.
- Cela permet de visualiser le tableau avant le début du tri.
- La fonction print_sort est définie dans le fichier 3-quick_sort.c.

4 - pivot = partition(array, size);

@pivot : index du pivot
@partition : fonction qui partitionne le tableau
@array : tableau d'entiers à partitionner
@size : taille du tableau

	- Appelle la fonction partition pour diviser le tableau en deux parties.
	- La fonction partition choisit un pivot et réorganise les éléments du tableau.
	- Elle retourne l'index du pivot après la partition.
	- Le tableau est divisé en deux sous-tableaux : ceux inférieurs au pivot et ceux supérieurs au pivot.

5 - quick_sort(array, pivot);

quick_sort : fonction récursive

Expliquer la fonction quick_sort
def quick_sort(array, pivot):
	- Appelle la fonction quick_sort de manière récursive sur la partie gauche du tableau.
	- Cette partie contient les éléments inférieurs au pivot.
	- Cela permet de trier cette sous-partie du tableau.

6 - quick_sort(array + pivot, size - pivot);

Trie récursivement la partie droite du tableau (les éléments à partir du pivot jusqu’à la fin).

array + pivot : déplacement du pointeur vers la droite.

pourquoi array + pivot ?
- Cela permet de passer à la partie droite du tableau.
- On utilise l'arithmétique des pointeurs pour accéder à la partie droite du tableau.

size - pivot : taille restante à droite du pivot.
- On soustrait l'index du pivot de la taille totale pour obtenir la taille de la partie droite.
- Cela permet de trier cette sous-partie du tableau.
- La fonction quick_sort est appelée de manière récursive pour trier cette partie.

🔁 Fonction swap

7 - void swap(int *a, int *b)

@void : type de retour de la fonction
@swap : nom de la fonction
@int : type entier
@a : pointeur vers le premier entier
@b : pointeur vers le deuxième entier

	- Cette fonction échange les valeurs de deux entiers.
	- Elle utilise un entier temporaire (tmp) pour effectuer l'échange.
	- Cela permet de réorganiser les éléments du tableau lors de la partition.
- La fonction swap est définie dans le fichier 3-quick_sort.c.
- Elle est utilisée pour échanger les éléments du tableau pendant le tri.
- La fonction swap est appelée dans la fonction partition pour échanger les éléments du tableau.

int tmp;
Expliquer la déclaration de tmp
- tmp : variable temporaire pour stocker la valeur de b.
- tmp est de type entier (int).
- tmp est utilisé pour effectuer l'échange entre les deux entiers a et b.

tmp = *b;	/* tmp prend la valeur de b */
*b = *a;	/* b prend la valeur de a */
*a = tmp;	/* a prend la valeur de tmp (ancien b) */

Échange la valeur de *a avec *b en utilisant la variable tmp.
- La valeur de b est stockée dans tmp.
- La valeur de a est assignée à b.
- La valeur de tmp (ancien b) est assignée à a.
- Cela permet d'échanger les valeurs des deux entiers.
- La fonction swap est utilisée pour échanger les éléments du tableau lors de la partition.
- Elle est essentielle pour le bon fonctionnement de l'algorithme de tri rapide.
- La fonction swap est appelée dans la fonction partition pour échanger les éléments du tableau.
- La fonction swap est définie dans le fichier 3-quick_sort.c.

🔀 Fonction partition
8 - size_t partition(int array[], size_t size)
@size_t : type entier non signé
@partition : nom de la fonction
@int : type entier
@array : tableau d'entiers à partitionner
@size : taille du tableau

	- Cette fonction partitionne le tableau en choisissant un pivot.
	- Elle réorganise les éléments du tableau en plaçant ceux inférieurs au pivot à gauche et ceux supérieurs à droite.
	- La fonction retourne l'index du pivot après la partition.
	- Cela permet de diviser le tableau en deux parties pour le tri rapide.
- La fonction partition est définie dans le fichier 3-quick_sort.c.


Cette fonction choisit un pivot et réorganise les éléments plus petits que lui à gauche, et les plus grands à droite.

size_t i = -1;
@size_t : type entier non signé
@i : variable pour l'indice de séparation
@int : type entier
@-1 : initialisation de i à -1

	- i est initialisé à -1 pour indiquer qu'aucun élément n'a encore été placé à gauche du pivot.
	- Cela permet de suivre la position d'insertion des éléments inférieurs au pivot.
	- La variable i est utilisée pour séparer les éléments inférieurs et supérieurs au pivot.
	- Elle est incrémentée chaque fois qu'un élément inférieur au pivot est trouvé.
size_t j;
@size_t : type entier non signé
@j : variable pour l'index de la boucle
int pivot : variable pour le pivot
@int : type entier
@pivot : valeur du pivot
i = -1 : c’est l’indice de séparation entre les petits et les grands éléments.
j : index de la boucle qui parcourt le tableau.

if (!array || size < 2)
    return (0);
Explication de la condition
- Vérifie si le tableau est vide ou si sa taille est inférieure à 2.
- Si c'est le cas, la fonction retourne 0.

pivot = array[size - 1];
@array : tableau d'entiers à partitionner
@int : type entier
@size - 1 : index du dernier élément du tableau
@array[size - 1] : dernier élément du tableau

for (j = 0; j < size - 1; j++)

Boucle sur tous les éléments sauf le pivot.
@j : index de la boucle
@size - 1 : on ne prend pas en compte le dernier élément (le pivot)
@j < size - 1 : condition de la boucle
@j++ : incrémentation de j à chaque itération
	- La boucle parcourt tous les éléments du tableau sauf le dernier (le pivot).
	- Elle compare chaque élément avec le pivot pour déterminer s'il doit être échangé.
	- Cela permet de réorganiser les éléments du tableau en fonction du pivot.
	- La boucle continue jusqu'à ce que tous les éléments aient été examinés.
	- La variable j est utilisée comme index pour parcourir le tableau.
	- La boucle commence à 0 et se termine à size - 1 (excluant le pivot).

	🎯 Intérieur de la boucle :

if (array[j] <= pivot)

Si l’élément courant est plus petit ou égal au pivot :
@array[j] : élément courant du tableau
@<= : opérateur de comparaison
@pivot : valeur du pivot
	- Vérifie si l'élément courant est inférieur ou égal au pivot.
	- Si c'est le cas, on doit échanger cet élément avec l'élément à la position i + 1.
	- Cela permet de placer les éléments inférieurs au pivot à gauche du tableau.
	- La condition permet de déterminer si l'élément doit être échangé ou non.
	- Si l'élément est inférieur ou égal au pivot, il doit être placé à gauche.
	- La condition est essentielle pour le bon fonctionnement de l'algorithme de tri rapide.

	i++;
On avance la zone des petits éléments.
@i : index de séparation
@++ : incrémentation de i
	- Incrémente i pour indiquer qu'un nouvel élément inférieur au pivot a été trouvé.
	- Cela permet de suivre la position d'insertion des éléments inférieurs au pivot.
	- La variable i est utilisée pour séparer les éléments inférieurs et supérieurs au pivot.
	- Elle est incrémentée chaque fois qu'un élément inférieur au pivot est trouvé.

	if (i != j)
S’il y a un écart entre i et j, on échange (sinon inutile).
@i : index de séparation
@j : index de la boucle
@!= : opérateur de comparaison
	- Vérifie si i et j sont différents.
	- Si c'est le cas, cela signifie qu'un échange est nécessaire.
	- Cela permet d'éviter des échanges inutiles lorsque i et j pointent déjà sur le même élément.
	- La condition permet d'optimiser l'algorithme en évitant des opérations superflues.
	- Si i et j sont égaux, il n'y a pas besoin d'échanger les éléments.
	- Cela permet de réduire le nombre d'opérations effectuées pendant la partition.
	swap(&array[i], &array[j]);
@swap : fonction d'échange
@&array[i] : adresse de l'élément à la position i
@&array[j] : adresse de l'élément à la position j
	- Appelle la fonction swap pour échanger les éléments à l'index i et j.
	- Cela place l'élément courant à la position correcte par rapport au pivot.
	- La fonction swap est définie dans le fichier 3-quick_sort.c.
	- Elle est utilisée pour échanger les éléments du tableau pendant la partition.
	- L'échange permet de réorganiser les éléments du tableau en fonction du pivot.
	- Cela permet de placer les éléments inférieurs au pivot à gauche et ceux supérieurs à droite.

	print_sort(array, size, 0);
@print_sort : fonction d'affichage du tableau
@array : tableau d'entiers à afficher
@size : taille du tableau
@0 : indique que c'est une étape intermédiaire
	- Appelle la fonction print_sort pour afficher l'état du tableau après chaque échange.
	- Cela permet de visualiser le processus de partitionnement.
	- La fonction print_sort est définie dans le fichier 3-quick_sort.c.
	- Elle est utilisée pour afficher le tableau à chaque étape de la partition.
	- Cela permet de suivre l'évolution du tableau pendant le tri rapide.

	🔁 Après la boucle :

if (i + 1 != size - 1)
@i + 1 : index du prochain élément
@size - 1 : index du dernier élément (le pivot)
@!= : opérateur de comparaison
	- Vérifie si l'index i + 1 est différent de size - 1 (le pivot).
	- Si c'est le cas, cela signifie qu'il faut échanger le pivot avec l'élément à la position i + 1.
	- Cela place le pivot à sa position correcte dans le tableau.
	- La condition permet de s'assurer que le pivot est placé au bon endroit.
	- Si i + 1 est égal à size - 1, il n'y a pas besoin d'échanger le pivot.

	- Cela permet de réduire le nombre d'opérations effectuées pendant la partition.
{
    swap(&array[i + 1], &array[size - 1]);
@swap : fonction d'échange
@&array[i + 1] : adresse de l'élément à la position i + 1
@&array[size - 1] : adresse de l'élément à la position size - 1 (le pivot)
	- Appelle la fonction swap pour échanger le pivot avec l'élément à la position i + 1.
	- Cela place le pivot à sa position correcte dans le tableau.

	print_sort(array, size, 0);
@print_sort : fonction d'affichage du tableau
@array : tableau d'entiers à afficher
@size : taille du tableau
@0 : indique que c'est une étape intermédiaire
	- Appelle la fonction print_sort pour afficher l'état du tableau après l'échange du pivot.
	- Cela permet de visualiser le tableau après la partition.
	- La fonction print_sort est définie dans le fichier 3-quick_sort.c.
	- Elle est utilisée pour afficher le tableau à chaque étape de la partition.
	- Cela permet de suivre l'évolution du tableau pendant le tri rapide.
}
return (i + 1);
On retourne l’indice final du pivot (sa position correcte dans le tableau trié).
@i + 1 : index du pivot
@return : retourne l'index du pivot
	- Retourne l'index du pivot après la partition.
	- Cela permet de diviser le tableau en deux parties pour le tri rapide.
	- La fonction retourne l'index du pivot pour que la fonction quick_sort puisse continuer à trier les sous-tableaux.
	- La valeur retournée est utilisée pour déterminer les limites des sous-tableaux à trier.
}

🖨️ Fonction print_sort

void print_sort(int array[], size_t size, int init)
@void : type de retour de la fonction
@print_sort : nom de la fonction
@int : type entier
@array : tableau d'entiers à afficher
@size : taille du tableau
@int : type entier
@init : indique si c'est l'initialisation du tableau
	- Cette fonction affiche le tableau d'entiers à chaque étape du tri.
	- Elle utilise une variable statique pour conserver l'état du tableau initial.
	- La fonction est définie dans le fichier 3-quick_sort.c.
	- Elle est utilisée pour afficher le tableau à chaque étape de la partition.
	- Cela permet de suivre l'évolution du tableau pendant le tri rapide.
	- La fonction print_sort est appelée dans la fonction partition pour afficher le tableau après chaque échange.

	static int *p = (void *)0;
@static : variable statique
@int *p : pointeur vers le tableau d'entiers
@void *0 : valeur nulle
	- p est un pointeur statique qui conserve l'état du tableau initial.
	- Il est initialisé à NULL (valeur nulle) pour indiquer qu'il n'a pas encore été assigné.

	static size_t s;
@static : variable statique
@size_t : type entier non signé
@s : variable pour la taille du tableau
	- s est une variable statique qui conserve la taille du tableau initial.
	- Elle est utilisée pour afficher le tableau à chaque étape du tri.
	- La variable s est initialisée à 0 pour indiquer qu'elle n'a pas encore été assignée.
	- Elle est utilisée pour stocker la taille du tableau initial.

	if (!p && init)
@p : pointeur vers le tableau d'entiers
@init : indique si c'est l'initialisation du tableau
	- Vérifie si p est NULL et si init est vrai (1).
	- Si c'est le cas, cela signifie que c'est la première fois que la fonction est appelée.
	- Cela permet d'initialiser p et s avec le tableau et sa taille.
	- La condition permet de s'assurer que p et s ne sont initialisés qu'une seule fois.
	- Cela évite de réinitialiser p et s à chaque appel de la fonction.
{
	p = array;	/* p prend l'adresse du tableau */
	s = size;	/* s prend la taille du tableau */
}
Si c’est le premier appel avec init == 1, on stocke le tableau de base (p) et sa taille (s).

if (!init)
@init : indique si c'est l'initialisation du tableau
@!init : condition inverse
	- Vérifie si init est faux (0).
	- Si c'est le cas, cela signifie que la fonction doit afficher le tableau.
	- Cela permet d'afficher le tableau à chaque étape du tri.

	print_array(p, s);
@print_array : fonction d'affichage du tableau
@p : pointeur vers le tableau d'entiers
@s : taille du tableau
	- Appelle la fonction print_array pour afficher le tableau d'entiers.
	- Cela permet de visualiser l'état du tableau à chaque étape du tri.
	- La fonction print_array est définie dans le fichier 3-quick_sort.c.
	- Elle est utilisée pour afficher le tableau à chaque étape de la partition.
	- Cela permet de suivre l'évolution du tableau pendant le tri rapide.
}









