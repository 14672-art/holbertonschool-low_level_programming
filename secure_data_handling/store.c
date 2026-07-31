#include <stdlib.h>
#include <string.h>
#include "store.h"

store_t *store_create(void)
{
	store_t *store;

	store = malloc(sizeof(store_t));
	if (!store)
		return (NULL);

	store->head = NULL;
	store->count = 0;

	return (store);
}

int store_insert(store_t *store, session_t *session)
{
	node_t *new_node;

	if (!store || !session || !session->id)
		return (-1);

	/* Rejet des doublons sans fuite mémoire */
	if (store_lookup(store, session->id) != NULL)
		return (-1);

	new_node = malloc(sizeof(node_t));
	if (!new_node)
		return (-1);

	new_node->session = session;
	new_node->next = store->head;
	store->head = new_node;
	store->count++;

	return (0);
}

session_t *store_lookup(store_t *store, const char *id)
{
	node_t *current;

	if (!store || !id)
		return (NULL);

	current = store->head;
	while (current)
	{
		if (current->session && current->session->id &&
		    strcmp(current->session->id, id) == 0)
			return (current->session);
		current = current->next;
	}

	return (NULL);
}

int store_remove(store_t *store, const char *id)
{
	node_t *current, *prev;

	if (!store || !id)
		return (-1);

	current = store->head;
	prev = NULL;

	while (current)
	{
		if (current->session && current->session->id &&
		    strcmp(current->session->id, id) == 0)
		{
			if (prev)
				prev->next = current->next;
			else
				store->head = current->next;

			session_destroy(current->session);
			current->session = NULL;
			current->next = NULL;
			free(current);
			store->count--;
			return (0);
		}
		prev = current;
		current = current->next;
	}

	return (-1);
}

void store_clear(store_t *store)
{
	node_t *current, *next;

	if (!store)
		return;

	current = store->head;
	store->head = NULL;
	store->count = 0;

	while (current)
	{
		next = current->next;

		if (current->session)
		{
			session_destroy(current->session);
			current->session = NULL;
		}

		current->next = NULL;
		free(current);
		current = next;
	}
}

void store_destroy(store_t *store)
{
	if (!store)
		return;

	store_clear(store);
	free(store);
}
