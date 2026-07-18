#include "variadic_functions.h"
#include <stdarg.h>

/**
 * sum_them_all - Calcule la somme de tous ses paramètres.
 * @n: Le nombre de paramètres passés à la fonction.
 * @...: Les paramètres variables à additionner.
 *
 * Return: La somme des paramètres, ou 0 si n == 0.
 */
int sum_them_all(const unsigned int n, ...)
{
	va_list args;
	unsigned int i;
	int sum = 0;

	if (n == 0)
	{
		return (0);
	}

	/* Initialisation de la liste d'arguments */
	va_start(args, n);

	/* Parcours de chaque argument variable */
	for (i = 0; i < n; i++)
	{
		sum += va_arg(args, int);
	}

	/* Nettoyage de la liste */
	va_end(args);

	return (sum);
}
