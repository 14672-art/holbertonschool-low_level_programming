#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_numbers - Affiche des nombres suivis d'une nouvelle ligne.
 * @separator: La chaîne à afficher entre les nombres.
 * @n: Le nombre d'entiers passés à la fonction.
 * @...: Les entiers à afficher.
 *
 * Return: Rien.
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list args;
	unsigned int i;

	va_start(args, n);

	for (i = 0; i < n; i++)
	{
		printf("%d", va_arg(args, int));

		/* On affiche le séparateur seulement s'il existe et si ce n'est pas le dernier élément */
		if (separator != NULL && i < n - 1)
		{
			printf("%s", separator);
		}
	}

	va_end(args);

	printf("\n");
}
