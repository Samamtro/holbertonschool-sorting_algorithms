#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 * using the Selection sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 *
 * Return: Nothing (void function).
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;	/* Déclaration des variables d'itération */
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
		min_idx = i;	/* Initialisation de l'indice du minimum */
	/* Boucle interne pour trouver l'élément minimum dans le reste du tableau */
		for (j = i + 1; j < size; j++)
			if (array[j] < array[min_idx])
				min_idx = j;	/* Mise à jour de l'indice du minimum */

		if (min_idx != i)	/* Si un nouvel élément minimum a été trouvé */
		{
			temp = array[i];	/* Stockage de la valeur actuelle */
			array[i] = array[min_idx];
			array[min_idx] = temp;

			print_array(array, size);	/* Affichage du tableau après chaque échange */
		}
	}
}
