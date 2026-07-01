#include "main.h"

/**
 * _strcpy - Copie la chaine src dans dest
 * @dest: Le tableau de destination
 * @src: La chaine d'origine
 *
 * Return: Le pointeur vers dest
 */
char *_strcpy(char *dest, char *src)
{
	int index = 0;

	/* On boucle tant qu'on n'est pas a la fin de la chaine source */
	while (src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}

	/* On rajoute bien le caractere de fin a la main */
	dest[index] = '\0';

	return (dest);
}
