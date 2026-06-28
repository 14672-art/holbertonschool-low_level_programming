#include "main.h"

/**
 * print_most_numbers - Imprime les chiffres de 0 à 9 (sauf 2 et 4),
 * suivis d'une nouvelle ligne.
 *
 * Return: void.
 */
void print_most_numbers(void)
{
	int i;

	for (i = '0'; i <= '9'; i++)
	{
		if (i != '2' && i != '4')
		{
			_putchar(i); /* Premier appel à _putchar */
		}
	}
	_putchar('\n'); /* Deuxième appel à _putchar */
}
