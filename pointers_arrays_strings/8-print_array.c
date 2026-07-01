#include "main.h"
#include <stdio.h>

/**
 * print_array - Affiche n éléments d'un tableau d'entiers.
 * @a: Le pointeur vers le tableau d'entiers.
 * @n: Le nombre d'éléments à afficher.
 *
 * Return: void.
 */
void print_array(int *a, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		/* Si ce n'est pas le premier élément, on ajoute la virgule et l'espace */
		if (i > 0)
		{
			printf(", ");
		}

		/* On affiche le nombre actuel */
		printf("%d", a[i]);
	}

	/* Fin de ligne obligatoire */
	printf("\n");
}
