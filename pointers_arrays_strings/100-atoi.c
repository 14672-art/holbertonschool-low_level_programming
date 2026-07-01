#include "main.h"

/**
 * _atoi - Convertit une chaîne de caractères en entier.
 * @s: La chaîne à convertir.
 *
 * Return: L'entier converti, ou 0 si aucun nombre n'est trouvé.
 */
int _atoi(char *s)
{
	int i = 0;
	int sign = 1;
	int res = 0;
	int found = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
		{
			sign *= -1;
		}
		else if (s[i] >= '0' && s[i] <= '9')
		{
			found = 1;
			/* Calcul direct en négatif pour esquiver le flag overflow */
			res = res * 10 - (s[i] - '0');
		}
		else if (found == 1)
		{
			break;
		}
		i++;
	}

	if (sign > 0)
	{
		return (-res);
	}

	return (res);
}
