#include <stdlib.h>
#include "lists.h"

/**
 * free_list - libère une liste chaînée list_t
 * @head: pointeur vers la tête de la liste
 */
void free_list(list_t *head)
{
	list_t *temp;

	while (head != NULL)
	{
		temp = head->next;
		free(head->str);
		free(head);
		head = temp;
	}
}
