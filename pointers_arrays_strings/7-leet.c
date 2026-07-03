#include "main.h"

/**
 * leet - Encode une chaine en 1337
 * @s: La chaine a encoder
 * Return: Le pointeur vers la chaine
 */
char *leet(char *s)
{
	int i = 0;
	int j;
	char lettres[] = "aAeEoOtTlL";
	char chiffres[] = "4433007711";

	while (s[i] != '\0')
	{
		for (j = 0; lettres[j] != '\0'; j++)
		{
			if (s[i] == lettres[j])
			{
				s[i] = chiffres[j];
			}
		}
		i++;
	}

	return (s);
}
