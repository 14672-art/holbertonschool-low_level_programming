#define _GNU_SOURCE
#include <stdlib.h>
#include <string.h>
#include "session.h"

/**
 * session_create - Crée une nouvelle session avec une copie profonde des données.
 * @id: Identifiant unique de la session.
 * @data: Pointeur vers les données de la session.
 * @data_len: Taille des données en octets.
 *
 * Return: Pointeur vers la session allouée, ou NULL en cas d'échec.
 */
session_t *session_create(const char *id, const void *data, size_t data_len)
{
	session_t *session;

	if (!id)
		return (NULL);

	session = malloc(sizeof(session_t));
	if (!session)
		return (NULL);

	session->id = NULL;
	session->data = NULL;
	session->data_len = 0;

	/* Deep copy de l'ID */
	session->id = strdup(id);
	if (!session->id)
	{
		free(session);
		return (NULL);
	}

	/* Deep copy des données si présentes */
	if (data && data_len > 0)
	{
		session->data = malloc(data_len);
		if (!session->data)
		{
			free(session->id);
			free(session);
			return (NULL);
		}
		memcpy(session->data, data, data_len);
		session->data_len = data_len;
	}

	return (session);
}

/**
 * session_destroy - Libère une session de manière sécurisée (écrasement mémoire).
 * @session: Pointeur vers la session à détruire.
 */
void session_destroy(session_t *session)
{
	if (!session)
		return;

	if (session->id)
	{
		free(session->id);
		session->id = NULL;
	}

	if (session->data)
	{
		memset(session->data, 0, session->data_len);
		free(session->data);
		session->data = NULL;
	}

	free(session);
}
