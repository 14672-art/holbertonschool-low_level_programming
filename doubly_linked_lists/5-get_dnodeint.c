#include "lists.h"

/**
 * get_dnodeint_at_index - Renvoie le n-ième nœud d'une liste dlistint_t
 * @head: Pointeur vers la tête de la liste
 * @index: L'index du nœud à récupérer (à partir de 0)
 *
 * Return: L'adresse du nœud ciblé, ou NULL si le nœud n'existe pas
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int i = 0;

	while (head != NULL)
	{
		if (i == index)
			return (head);

		head = head->next;
		i++;
	}

	return (NULL);
}
