#include "main.h"
#include <stddef.h>

/**
 * _strpbrk - recherche un ensemble d'octets dans une chaine
 * @s: la chaine a analyser
 * @accept: les caracteres a rechercher
 *
 * Return: un pointeur vers l'octet correspondant dans s, ou NULL
 */
char *_strpbrk(char *s, char *accept)
{
	int i;

	while (*s != '\0')
	{
		for (i = 0; accept[i] != '\0'; i++)
		{
			if (*s == accept[i])
			{
				return (s);
			}
		}
		s++;
	}

	return (NULL);
}
