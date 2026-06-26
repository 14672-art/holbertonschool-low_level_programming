#include <stdio.h>

/**
 * main - Point d'entree du programme
 *
 * Description: Affiche les chiffres de 0 a 9 separes par des virgules.
 * Return: Toujours 0 (Succes)
 */
int main(void)
{
	int num;

	for (num = 48; num <= 57; num++)
	{
		putchar(num);

		if (num < 57)
		{
			putchar(',');
			putchar(' ');
		}
	}
	putchar('\n');

	return (0);
}
