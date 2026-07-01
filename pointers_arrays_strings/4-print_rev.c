#include "main.h"

/**
 * print_rev - Affiche une chaîne en inversé, suivie d'un retour à la ligne.
 * @s: La chaîne de caractères à afficher.
 *
 * Return: void.
 */
void print_rev(char *s)
{
	int length = 0;

	/* Calcule la longueur de la chaîne */
	while (s[length] != '\0')
	{
		length++;
	}

	/* Parcourt et affiche la chaîne en partant de la fin */
	for (length--; length >= 0; length--)
	{
		_putchar(s[length]);
	}

	_putchar('\n');
}
