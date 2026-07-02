#include "main.h"

/**
 * _strncat - Concatenates two strings using at most n bytes from src
 * @dest: The destination string
 * @src: The source string
 * @n: The maximum number of bytes to copy from src
 *
 * Return: A pointer to the resulting string dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int i = 0;
	int j = 0;

	/* 1. On va jusqu'au bout de dest */
	while (dest[i] != '\0')
	{
		i++;
	}

	/* 2. On copie src dans dest, MAIS avec la limite n */
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}

	/* 3. On ferme TOUJOURS la chaîne avec le null byte */
	dest[i] = '\0';

	return (dest);
}
