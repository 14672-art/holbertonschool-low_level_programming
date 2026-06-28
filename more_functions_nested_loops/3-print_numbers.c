#include "main.h"

/**
 * print_numbers - Imprime les chiffres de 0 à 9, suivis d'une nouvelle ligne.
 *
 * Return: void.
 */
void print_numbers(void)
{
	int i;

	for (i = '0'; i <= '9'; i++)
	{
		_putchar(i); /* Premier appel à _putchar */
	}
	_putchar('\n'); /* Deuxième appel à _putchar */
}
