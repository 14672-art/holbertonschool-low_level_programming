#include "main.h"

/**
 * _strncat - Concatenates two strings using at most n bytes from src.
 * @dest: The destination string.
 * @src: The source string.
 * @n: The maximum number of bytes to copy from src.
 *
 * Return: A pointer to the resulting string dest.
 */
char *_strncat(char *dest, char *src, int n)
{
	int i = 0;
	int j = 0;

	/* On avance jusqu'à la fin de dest */
	while (dest[i] != '\0')
	{
		i++;
	}

	/* On copie src dans dest avec la double condition */
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}

	/* On ajoute le null byte final pour clore proprement */
	dest[i] = '\0';

	return (dest);
}
