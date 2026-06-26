#include "main.h"

/**
 * _isalpha - Verifie si un caractere est une lettre
 * @c: Le caractere a tester
 *
 * Return: 1 si c'est une lettre (maj ou min), 0 sinon.
 */
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
