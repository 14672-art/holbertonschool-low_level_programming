#include <stdio.h>

/**
 * main - Point d'entree du programme
 *
 * Description: Affiche les chiffres de 0 a 9 avec putchar et un int.
 * Return: Toujours 0 (Succes)
 */
int main(void)
{
	int num;

	for (num = 48; num <= 57; num++)
	{
		putchar(num);
	}
	putchar('\n');

	return (0);
}
