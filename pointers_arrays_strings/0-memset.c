#include "main.h"

/**
 * _memset - remplit la memoire avec un octet constant
 * @s: zone memoire a remplir
 * @b: octet constant a copier
 * @n: nombre d'octets a modifier
 *
 * Return: le pointeur vers la zone memoire s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}

	return (s);
}
