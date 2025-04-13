#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * quick_sort - Function that sorts an array based on
 * quick sort algorithm
 * @array: Array to be sorted
 * @size: Size of array
 * Return: 0
 */
void quick_sort(int *array, size_t size)	/* Fonction de tri rapide */
{
	/* Déclaration des variables */
	size_t pivot;
	/* Vérifie si le tableau est vide ou a moins de 2 éléments */
	if (!array || size < 2)
		return;	/* Retourne si le tableau est vide ou a moins de 2 éléments */
	/* Appelle la fonction print_sort pour afficher le tableau initial */
	print_sort(array, size, 1);

	/* Partitionne le tableau et récupère l'index du pivot */
	pivot = partition(array, size);


	quick_sort(array, pivot);	/* appel récursif pour la partie gauche */
	/*
	 * Appel récursif sur la partie droite du pivot (inclut le pivot ici,
	 * ce qui pourrait être une erreur)
	 */
	quick_sort(array + pivot, size - pivot);
}

/**
 * swap - Function that swaps two values
 *
 * @a: Fisrt value
 * @b: Second value
 * Return: 0
 */
void swap(int *a, int *b)	/* Fonction d'échange */
{
	int tmp;	/* Déclaration d'une variable temporaire */

	tmp = *b;	/* Stocke la valeur de b dans tmp */
	*b = *a;	/* Assigne la valeur de a à b */
	*a = tmp;	/* Assigne la valeur de tmp (ancien b) à a */
}

/**
 * partition - Function that sets the pivot for quick_sort
 *
 * @array: Array to partition
 * @size: Size of array
 * Return: (i + 1)
 */
size_t partition(int array[], size_t size)	/* Fonction de partitionnement */
{
	int pivot;	/* Déclaration de la variable pivot */
	size_t i = -1;	/* Initialisation de i à -1 */
	size_t j;	/* Déclaration de la variable j */
	/* Vérifie si le tableau est vide ou a moins de 2 éléments */
	if (!array || size < 2)
	/* Retourne 0 si le tableau est vide ou a moins de 2 éléments */
		return (0);

	pivot = array[size - 1];	/* Définit le dernier élément comme pivot */
	/* Parcourt le tableau jusqu'à l'avant-dernier élément */
	for (j = 0; j < size - 1; j++)
	{
		/* Si l'élément courant est inférieur ou égal au pivot */
		if (array[j] <= pivot)
		{
			i++;	/* Incrémente i */
			/* Si i et j ne sont pas égaux, échange les éléments */
			if (i != j)
			{	/* Échange les éléments à l'index i et j */
				/* Appelle la fonction swap pour échanger les éléments */
				swap(&array[i], &array[j]);
				/* Affiche le tableau après l'échange */
				/* Appelle la fonction print_sort pour afficher le tableau */
				print_sort(array, size, 0);
			}
		}
	}
	if (i + 1 != size - 1)	/* Si i + 1 n'est pas égal à size - 1 */
	{
		/* Échange le pivot avec l'élément à l'index i + 1 */
		/* Appelle la fonction swap pour échanger le pivot avec l'élément */
		/* à l'index i + 1 */
		/* Appelle la fonction swap pour échanger les éléments */
		swap(&array[i + 1], &array[size - 1]);
		print_sort(array, size, 0);	/* Affiche le tableau après l'échange */
		/* Appelle la fonction print_sort pour afficher le tableau */
	}
	return (i + 1);	/* Retourne l'index du pivot */
	/* Retourne l'index du pivot (i + 1) */
}

/**
 * print_sort - Function that prints as it should
 * @array: Array to be printed
 * @size: Size of array
 * @init: Should initialize array
 * Return: 0
 */
void print_sort(int array[], size_t size, int init)	/* Fonction d'affichage */
{
	static int *p = (void *)0;	/* Pointeur statique vers le tableau */
	/* Initialisation du pointeur p à NULL */
	/* Déclaration d'une variable statique pour la taille */
	static size_t s;	/* Taille du tableau */
	/* Vérifie si le tableau est vide ou a moins de 2 éléments */
	/* Initialisation à la première exécution de la fonction */
	if (!p && init)
	{
		p = array;	/* Assigne le tableau à p */
		s = size;	/* Assigne la taille à s */
	}
	if (!init)	/* Si init est faux */
		print_array(p, s);	/* Affiche le tableau */
}
