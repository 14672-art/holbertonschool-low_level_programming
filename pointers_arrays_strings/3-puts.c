#include "main.h"

/**
 * _puts - Imprime une chaîne de caractères suivie d'une nouvelle ligne.
 * @str: Pointeur vers la chaîne de caractères à afficher.
 *
 * Return: void.
 */
void _puts(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
	_putchar('\n');
}
