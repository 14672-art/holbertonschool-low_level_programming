#include "main.h"

/**
 * _atoi - Convertit une chaine de caracteres en entier.
 * @s: La chaine a convertir.
 *
 * Return: L'entier converti, ou 0 si aucun nombre.
 */
int _atoi(char *s)
{
	int index = 0;
	int signe = 1;
	unsigned int resultat = 0;
	int indicateur = 0;

	while (s[index] != '\0')
	{
		if (s[index] == '-')
		{
			signe *= -1;
		}
		else if (s[index] >= '0' && s[index] <= '9')
		{
			indicateur = 1;
			resultat = (resultat * 10) + (s[index] - '0');
		}
		else if (indicateur == 1)
		{
			break;
		}
		index++;
	}

	return (resultat * signe);
}
