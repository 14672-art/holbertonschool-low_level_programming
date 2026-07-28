#include "lists.h"
#include <stdlib.h>

/**
 * insert_dnodeint_at_index - Insère un nouveau nœud à une position donnée
 * @h: Pointeur vers le pointeur de la tête de la liste
 * @idx: L'index où ajouter le nouveau nœud (commence à 0)
 * @n: La valeur à stocker dans le nœud
 *
 * Return: L'adresse du nouveau nœud, ou NULL en cas d'échec
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node, *temp;
	unsigned int i = 0;

	if (h == NULL)
		return (NULL);

	/* Si l'insertion se fait au début (index 0) */
	if (idx == 0)
		return (add_dnodeint(h, n));

	temp = *h;

	/* Parcourir la liste jusqu'à l'élément précédant la position souhaitée */
	while (temp != NULL && i < idx - 1)
	{
		temp = temp->next;
		i++;
	}

	/* Si l'index est invalide (en dehors de la liste) */
	if (temp == NULL)
		return (NULL);

	/* Si l'insertion se fait à la toute fin */
	if (temp->next == NULL)
		return (add_dnodeint_end(h, n));

	/* Création et insertion du nouveau nœud au milieu */
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
