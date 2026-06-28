#include "main.h"

/**
 * _isupper - Vérifie si un caractère est une majuscule.
 * @c: Le caractère à tester (représenté par son code ASCII).
 *
 * Return: 1 si c est une majuscule, 0 sinon.
 */
int _isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (1);
	}
	return (0);
}
