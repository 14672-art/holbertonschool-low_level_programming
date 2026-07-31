#include <stdlib.h>
#include <string.h>
#include "store.h"

/**
 * store_create - Initialise le magasin de sessions.
 *
 * Return: Pointeur vers le store alloué, ou NULL en cas d'échec.
 */
store_t *store_create(void)
{
	store_t *store;

	store = malloc(sizeof(store_t));
	if (!store)
		return (NULL);

	store->head = NULL;

	return (store);
}

/**
 * store_lookup - Recherche une session par son ID.
 * @store: Pointeur vers le magasin.
 * @id: Identifiant recherché.
 *
 * Return: Pointeur vers la session si trouvée, NULL sinon.
 */
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

/**
 * store_insert - Insère une session de manière sécurisée dans le magasin.
 * @store: Pointeur vers le magasin.
 * @session: Session à insérer.
 *
 * Return: 0 en cas de succès, -1 en cas d'échec ou de doublon.
 */
int store_insert(store_t *store, session_t *session)
{
	node_t *new_node;

	if (!store || !session || !session->id)
		return (-1);

	/* Evite les doublons */
	if (store_lookup(store, session->id) != NULL)
		return (-1);

	new_node = malloc(sizeof(node_t));
	if (!new_node)
		return (-1);

	new_node->session = session;
	new_node->next = store->head;
	store->head = new_node;

	return (0);
}

/**
 * store_remove - Supprime une session spécifique du magasin.
 * @store: Pointeur vers le magasin.
 * @id: Identifiant de la session à supprimer.
 *
 * Return: 0 en cas de succès, -1 si non trouvée.
 */
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
			return (0);
		}
		prev = current;
		current = current->next;
	}

	return (-1);
}

/**
 * store_clear - Vidage défensif et réutilisable du magasin.
 * @store: Pointeur vers le magasin à vider.
 */
void store_clear(store_t *store)
{
	node_t *current, *next;

	if (!store)
		return;

	current = store->head;
	store->head = NULL;

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

/**
 * store_destroy - Détruit le magasin et libère toute la mémoire.
 * @store: Pointeur vers le magasin.
 */
void store_destroy(store_t *store)
{
	if (!store)
		return;

	store_clear(store);
	free(store);
}
