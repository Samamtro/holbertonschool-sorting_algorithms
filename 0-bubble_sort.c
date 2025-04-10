#include <stdio.h>
#include <stdlib.h>
#include "sort.h"


/**
 * bubble_sort - Sorts an array of integers in ascending order
 * using the Bubble sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 *
 * Return: Nothing (void function).
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;	/* Déclaration des variables d'itération */
	int temp;	/* Variable temporaire pour l'échange des valeurs */

	/* Vérification des cas d'erreur */
	if (array == NULL || size < 2)
	/*
	 * Retour immédiat si le tableau est NULL ou de taille insuffisante
	 * pour être trié
	 */
		return;
	/* Boucle externe pour le nombre total de passages */
	for (i = 0; i < size - 1; i++)
	{
		/* Boucle interne pour comparer et échanger les éléments adjacents */
		for (j = 0; j < size - i - 1; j++)
		{
			/* Comparaison des éléments adjacents*/
			if (array[j] > array[j + 1])
			{
				/* Échange des éléments s'ils sont dans le mauvais ordre */
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;

				/* Affichage du tableau après chaque échange */
				print_array(array, size);
			}
		}
	}
}
