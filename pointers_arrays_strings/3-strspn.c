#include "main.h"

/**
 * _strspn - calcule la longueur du segment initial d'une chaine
 * @s: la chaine principale a analyser
 * @accept: la liste des caracteres autorises
 *
 * Return: le nombre d'octets du segment initial de s valides
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int i;
	unsigned int j;
	unsigned int count;
	int match;

	count = 0;
	for (i = 0; s[i] != '\0'; i++)
	{
		match = 0;
		for (j = 0; accept[j] != '\0'; j++)
		{
			if (s[i] == accept[j])
			{
				match = 1;
				break;
			}
		}
		if (match == 0)
		{
			return (count);
		}
		count++;
	}

	return (count);
}
