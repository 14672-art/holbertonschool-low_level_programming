#include "function_pointers.h"
#include <stddef.h>

/**
 * print_name - Affiche un nom en utilisant un pointeur de fonction.
 * @name: La chaîne de caractères contenant le nom.
 * @f: Le pointeur vers la fonction qui va formater et afficher le nom.
 *
 * Return: Rien.
 */
void print_name(char *name, void (*f)(char *))
{
	if (name != NULL && f != NULL)
	{
		f(name);
	}
}
