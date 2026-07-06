#include "main.h"
#include <stdio.h>

/**
 * print_diagsums - affiche la somme des deux diagonales
 * @a: pointeur vers la matrice (tableau 1D)
 * @size: la taille de la matrice (largeur/hauteur)
 *
 * Return: void
 */
void print_diagsums(int *a, int size)
{
	int i;
	int sum1;
	int sum2;

	sum1 = 0;
	sum2 = 0;

	for (i = 0; i < size; i++)
	{
		sum1 += a[i * (size + 1)];
		sum2 += a[(i + 1) * (size - 1)];
	}

	printf("%d, %d\n", sum1, sum2);
}
