#include "function_pointers.h"
#include <stddef.h>

/**
 * int_index - Recherche un entier dans un tableau selon une fonction de comparaison.
 * @array: Le tableau d'entiers.
 * @size: Le nombre d'éléments dans le tableau.
 * @cmp: Le pointeur vers la fonction de comparaison.
 *
 * Return: L'index du premier élément correspondant, ou -1 en cas d'échec.
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array != NULL && cmp != NULL && size > 0)
	{
		for (i = 0; i < size; i++)
		{
			if (cmp(array[i]) != 0)
			{
				return (i);
			}
		}
	}

	return (-1);
}
