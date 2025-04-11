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
{	/* Déclaration des pointeurs */
	/*
	 * list : Pointeur vers la tête de la liste chaînée
	 * current : Pointeur vers l'élément courant de la liste
	 * temp : Pointeur vers l'élément à insérer dans la liste triée
	 * next : Pointeur vers l'élément suivant de la liste
	 */
	listint_t *current, *temp, *next;	/* Pointeur vers l'élément courant */
	/* Vérifie si la liste est vide ou contient un seul élément */
	if (list == NULL || *list == NULL)
	{
		return;	/* Retourne immédiatement si la liste est vide ou nulle */
	}
	/* Initialise le pointeur courant à l'élément suivant de la tête */
	current = (*list)->next;
	while (current != NULL)	/* Parcourt la liste jusqu'à la fin */
	{
		temp = current;	/* Pointeur vers l'élément à insérer */
		next = current->next;	/* Pointeur vers l'élément suivant de la liste */
		/* Déplacement du nœud actuel vers sa position correcte */
		while (temp->prev != NULL && temp->n < temp->prev->n)
		{	/* Détache temp de sa position actuelle */
			temp->prev->next = temp->next;
			/* Si temp n'était pas le dernier élément, ajuste son successeur */
			if (temp->next != NULL)
				temp->next->prev = temp->prev;	/* Ajuste le prédécesseur de temp */
			/* Insère temp avant son prédécesseur */
			 /* L'ancien prédécesseur devient le suivant */
			temp->next = temp->prev;
			/* temp prend la place de l'ancien prédécesseur */
			temp->prev = temp->prev->prev;
			temp->next->prev = temp;	/* Mise à jour du lien arrière */
			if (temp->prev != NULL)	/* Si temp n'est pas le premier élément */
				temp->prev->next = temp;	/* Mise à jour du lien avant */
			else
			/* Si temp est le premier élément, met à jour la tête de la liste */
				*list = temp;
			print_list(*list);	/* Affiche la liste après chaque modification */
			}
			current = next;	/* Passe au nœud suivant dans la liste */
	}
}
