#include "main.h"

/**
 * print_triangle - Imprime un triangle aligné à droite,
 * suivi d'une nouvelle ligne.
 * @size: La taille du triangle.
 *
 * Return: void.
 */
void print_triangle(int size)
{
	int i, j;

	if (size > 0)
	{
		for (i = 1; i <= size; i++)
		{
			/* Imprime les espaces nécessaires */
			for (j = 0; j < (size - i); j++)
			{
				_putchar(' ');
			}
			/* Imprime les # correspondants */
			for (j = 0; j < i; j++)
			{
				_putchar('#');
			}
			_putchar('\n');
		}
	}
	else
	{
		_putchar('\n');
	}
}
