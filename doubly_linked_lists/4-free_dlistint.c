#include "lists.h"
#include <stdlib.h>

/**
 * free_dlistint - Libère une liste chaînée dlistint_t
 * @head: Pointeur vers la tête de la liste
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *temp;

	while (head != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
