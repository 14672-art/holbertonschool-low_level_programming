#include "lists.h"

/**
 * sum_dlistint - Calcule la somme de toutes les données (n) d'une liste
 * @head: Pointeur vers la tête de la liste
 *
 * Return: La somme des données, ou 0 si la liste est vide
 */
int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}

	return (sum);
}
