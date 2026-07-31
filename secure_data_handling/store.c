#include <stdlib.h>
#include <string.h>
#include "store.h"

/**
 * store_create - Initialise une nouvelle structure de magasin.
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
	store->count = 0;

	return (store);
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

	/* Vérification des doublons pour éviter la corruption */
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

/**
 * store_lookup - Recherche une session par son identifiant.
 * @store: Pointeur vers le magasin.
 * @id: Identifiant de la session.
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
 * store_remove - Supprime une session spécifique du magasin.
 * @store: Pointeur vers le magasin.
 * @id: Identifiant de la session à supprimer.
 *
 * Return: 0 si la suppression a réussi, -1 si non trouvée.
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

			/* Destruction sécurisée de la session */
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

/**
 * store_clear - Vidage défensif et répétable du magasin.
 * @store: Pointeur vers le magasin à vider.
 */
void store_clear(store_t *store)
{
	node_t *current, *next;

	if (!store)
		return;

	current = store->head;
	store->head = NULL; /* Invalidation immédiate de la tête */
	store->count = 0;   /* Réinitialisation du compteur */

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
 * store_destroy - Libère le magasin et réinitialise son pointeur.
 * @store: Pointeur vers le magasin.
 */
void store_destroy(store_t *store)
{
	if (!store)
		return;

	/* Nettoyage complet des nœuds et des sessions */
	store_clear(store);

	/* Libération de la structure magasin elle-même */
	free(store);
}
