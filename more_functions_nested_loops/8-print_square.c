#include "main.h"

/**
 * print_square - Imprime un carré dans le terminal suivi d'une nouvelle ligne.
 * @size: La taille du carré (largeur et hauteur).
 *
 * Return: void.
 */
void print_square(int size)
{
	int i, j;

	if (size > 0)
	{
		for (i = 0; i < size; i++)
		{
			for (j = 0; j < size; j++)
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
