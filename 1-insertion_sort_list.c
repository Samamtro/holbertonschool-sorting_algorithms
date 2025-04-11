#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in
 * ascending order using the Insertion sort algorithm.
 * @list: A pointer to the head of the doubly linked list.
 *
 * Return: Nothing (void function).
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp, *next_node;

	/* Vérifie si la liste est vide ou contient un seul élément */
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	/* Commence le tri à partir du deuxième élément */
	current = (*list)->next;
	while (current != NULL)	/* Parcourt la liste à partir du dexieme element */
	{
		/* Stocke le prochain nœud avant modification */
		next_node = current->next;
		temp = current->prev; /* Pointeur temporaire vers le nœud précédent */

		/* Déplace le nœud actuel à sa position correcte dans la liste */
		while (temp != NULL && current->n < temp->n)
		{
			/* Échange des nœuds */
			if (temp->prev != NULL)	/* Si temp n'est pas le premier nœud */
			/* Ajuste le lien du nœud précédent */
				temp->prev->next = current;
			else	/* Met à jour la tête de la liste si nécessaire */
				*list = current;
			/* Met à jour le pointeur prev de current */
			current->prev = temp->prev;
			temp->prev = current;	/* Met à jour le pointeur prev de temp */
			current->next = temp;	/* current pointe maintenant vers temp */
			temp->next = next_node;	/* temp pointe maintenant vers next_node */

			/* Si next_node existe, ajuste son pointeur prev */
			if (next_node != NULL)
				next_node->prev = temp;	/* next_node pointe vers temp */
			/* Si temp n'est pas le dernier nœud, ajuste son pointeur next */

			print_list(*list); /* Affiche la liste après chaque échange */
			/* Continue de comparer avec le nœud précédent */
			temp = current->prev;
		}
		current = next_node; /* Passe au prochain élément de la liste */
	}
}
