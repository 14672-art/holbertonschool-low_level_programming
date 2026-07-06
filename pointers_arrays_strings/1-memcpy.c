#include "main.h"

/**
 * _memcpy - copie une zone memoire
 * @dest: zone memoire de destination
 * @src: zone memoire source
 * @n: nombre d'octets a copier
 *
 * Return: le pointeur vers dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}

	return (dest);
}
