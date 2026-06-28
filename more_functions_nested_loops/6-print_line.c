#include "main.h"

/**
 * print_line - Trace une ligne droite dans le terminal.
 * @n: Le nombre de fois que le caractère _ doit être affiché.
 *
 * Return: void.
 */
void print_line(int n)
{
	int i;

	if (n > 0)
	{
		for (i = 0; i < n; i++)
		{
			_putchar('_');
		}
	}
	_putchar('\n');
}
