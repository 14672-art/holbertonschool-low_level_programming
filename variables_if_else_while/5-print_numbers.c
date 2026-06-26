#include <stdio.h>

/**
 * main - Point d'entree du programme
 *
 * Description: Affiche les chiffres de 0 a 9 en base 10.
 * Return: Toujours 0 (Succes)
 */
int main(void)
{
	int num;

	for (num = 0; num < 10; num++)
	{
		printf("%d", num);
	}
	printf("\n");

	return (0);
}
