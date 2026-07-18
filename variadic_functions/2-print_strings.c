#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_strings - Affiche des chaînes suivies d'une nouvelle ligne.
 * @separator: La chaîne à afficher entre les chaînes.
 * @n: Le nombre de chaînes passées à la fonction.
 * @...: Les chaînes à afficher.
 *
 * Return: Rien.
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list args;
	unsigned int i;
	char *str;

	va_start(args, n);

	for (i = 0; i < n; i++)
	{
		str = va_arg(args, char *);

		if (str == NULL)
		{
			printf("(nil)");
		}
		else
		{
			printf("%s", str);
		}

		/* Affiche le séparateur s'il existe et si pas le dernier */
		if (separator != NULL && i < n - 1)
		{
			printf("%s", separator);
		}
	}

	va_end(args);

	printf("\n");
}
