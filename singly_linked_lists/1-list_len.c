#include "lists.h"

/**
 * list_len - retourne le nombre d'éléments dans une liste chaînée list_t
 * @h: pointeur vers la tête de la liste
 *
 * Return: le nombre de nœuds dans la liste
 */
size_t list_len(const list_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		count++;
		h = h->next;
	}

	return (count);
}
