#define _GNU_SOURCE
#include <stdlib.h>
#include <string.h>
#include "session.h"

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

	session->id = strdup(id);
	if (!session->id)
	{
		free(session);
		return (NULL);
	}

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
