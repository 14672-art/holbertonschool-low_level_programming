#include "main.h"
#include <stddef.h>

/**
 * _strstr - localise une sous-chaine
 * @haystack: la chaine principale dans laquelle chercher
 * @needle: la sous-chaine a trouver
 *
 * Return: un pointeur vers le debut de la sous-chaine, ou NULL
 */
char *_strstr(char *haystack, char *needle)
{
	int i;
	int j;

	if (*needle == '\0')
	{
		return (haystack);
	}

	for (i = 0; haystack[i] != '\0'; i++)
	{
		j = 0;
		while (haystack[i + j] == needle[j])
		{
			if (needle[j + 1] == '\0')
			{
				return (&haystack[i]);
			}
			j++;
		}
	}

	return (NULL);
}
