#include "main.h"

/**
 * _islower - Verifie si un caractere est en minuscule
 * @c: Le caractere a tester (represente par son code ASCII)
 *
 * Return: 1 si le caractere est une minuscule, 0 sinon.
 */
int _islower(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
