#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Supprime le noeud a un index donne
 * @head: Pointeur vers le pointeur de la tete de la liste
 * @index: L'index du noeud a supprimer (commence a 0)
 *
 * Return: 1 si reussi, -1 en cas d'echec
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *temp;
	unsigned int i = 0;

	if (head == NULL || *head == NULL)
		return (-1);

	temp = *head;

	/* Suppression du premier noeud */
	if (index == 0)
	{
		*head = temp->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(temp);
		return (1);
	}

	/* Parcourir la liste jusqu'au noeud cible */
	while (temp != NULL && i < index)
	{
		temp = temp->next;
		i++;
	}

	/* Si l'index est en dehors de la liste */
	if (temp == NULL)
		return (-1);

	/* Mise a jour des pointeurs pour isoler et liberer le noeud */
	if (temp->next != NULL)
		temp->next->prev = temp->prev;

	if (temp->prev != NULL)
		temp->prev->next = temp->next;

	free(temp);
	return (1);
}
