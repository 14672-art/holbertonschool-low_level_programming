#include "main.h"

/**
 * print_last_digit - Imprime et retourne le dernier chiffre d'un nombre
 * @n: Le nombre dont on extrait le dernier chiffre
 *
 * Return: La valeur du dernier chiffre (toujours positive)
 */
int print_last_digit(int n)
{
	int last_digit;

	last_digit = n % 10;

	if (last_digit < 0)
	{
		last_digit = -last_digit;
	}

	_putchar(last_digit + '0');

	return (last_digit);
}
