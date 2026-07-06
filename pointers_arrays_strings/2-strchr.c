#include "main.h"
#include <stddef.h>

/**
 * _strchr - localise un caractere dans une chaine
 * @s: la chaine de caracteres
 * @c: le caractere a rechercher
 *
 * Return: un pointeur vers la premiere occurrence ou NULL
 */
char *_strchr(char *s, char c)
{
	while (*s >= '\0')
	{
		if (*s == c)
		{
			return (s);
		}
		if (*s == '\0')
		{
			return (NULL);
		}
		s++;
	}
	return (NULL);
}
