#include "main.h"

/**
 * _strncpy - Copies a string up to n bytes.
 * @dest: The destination buffer.
 * @src: The source string.
 * @n: The maximum number of bytes to copy.
 *
 * Return: A pointer to the destination string dest.
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i = 0;

	/* 1. On copie src dans dest tant qu'on a des caractères et qu'on respecte n */
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}

	/* 2. Le piège : si src était plus courte que n, on remplit le reste de \0 */
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}

	return (dest);
}
