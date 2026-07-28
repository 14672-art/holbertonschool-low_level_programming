#include "lists.h"
#include <stdlib.h>

/**
 * insert_dnodeint_at_index - Insere un noeud a une position donnee
 * @h: Pointeur vers le pointeur de la tete de la liste
 * @idx: L'index ou ajouter le nouveau noeud (commence a 0)
 * @n: La valeur a stocker dans le noeud
 *
 * Return: L'adresse du nouveau noeud, ou NULL en cas d'echec
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node, *temp;
	unsigned int i = 0;

	if (h == NULL)
		return (NULL);

	if (idx == 0)
		return (add_dnodeint(h, n));

	temp = *h;

	/* Parcourir la liste jusqu'au noeud precedent */
	while (temp != NULL && i < idx - 1)
	{
		temp = temp->next;
		i++;
	}

	if (temp == NULL)
		return (NULL);

	if (temp->next == NULL)
		return (add_dnodeint_end(h, n));

	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = temp->next;
	new_node->prev = temp;

	temp->next->prev = new_node;
	temp->next = new_node;

	return (new_node);
}
