#include "main.h"

/**
 * _strcmp - Compares two strings.
 * @s1: The first string to compare.
 * @s2: The second string to compare.
 *
 * Return: An integer less than, equal to, or greater than zero.
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	/* On boucle tant qu'on n'est pas à la fin et que c'est identique */
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}

	/* On retourne la différence des caractères là où ça a bloqué */
	return (s1[i] - s2[i]);
}
