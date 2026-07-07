#include "main.h"
#include <stdlib.h>

/**
 * _strdup - Duplicates a string in a newly allocated memory space.
 * @str: The string to duplicate.
 *
 * Return: A pointer to the duplicated string, or NULL if fails or str is NULL.
 */
char *_strdup(char *str)
{
	char *dup;
	unsigned int i, len;

	if (str == NULL)
	{
		return (NULL);
	}

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}

	dup = malloc(sizeof(char) * (len + 1));

	if (dup == NULL)
	{
		return (NULL);
	}

	i = 0;
	while (i < len)
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';

	return (dup);
}
