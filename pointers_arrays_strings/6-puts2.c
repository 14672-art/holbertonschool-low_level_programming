#include "main.h"

/**
 * puts2 - Affiche un caractère sur deux d'une chaîne.
 * @str: La chaîne de caractères à parcourir.
 *
 * Return: void.
 */
void puts2(char *str)
{
	int i = 0;

	/* On avance de 2 en 2 tant qu'on n'est pas à la fin de la chaîne */
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i += 2;

		/* Sécurité si la chaîne s'arrête juste après l'incrémentation */
		if (str[i - 1] == '\0')
		{
			break;
		}
	}

	_putchar('\n');
}
