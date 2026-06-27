#include <stdio.h>
#include "main.h"

/**
 * print_to_98 - Affiche tous les nombres de n jusqu'a 98
 * @n: Le nombre de depart
 */
void print_to_98(int n)
{
	if (n <= 98)
	{
		for (; n < 98; n++)
		{
			printf("%d, ", n);
		}
	}
	else
	{
		for (; n > 98; n--)
		{
			printf("%d, ", n);
		}
	}
	printf("%d\n", 98);
}
