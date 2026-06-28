#include "main.h"

/**
 * print_diagonal - Dessine une ligne diagonale dans le terminal.
 * @n: Le nombre de fois que le caractère \ doit être affiché.
 *
 * Return: void.
 */
void print_diagonal(int n)
{
	int i, j;

	if (n > 0)
	{
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < i; j++)
			{
				_putchar(' ');
			}
			_putchar('\\'); /* On double l'antislash pour l'échapper en C */
			_putchar('\n');
		}
	}
	else
	{
		_putchar('\n');
	}
}
