#include <stdio.h>

/**
 * main - Point d'entree du programme
 *
 * Description: Affiche l'alphabet en minuscules a l'envers.
 * Return: Toujours 0 (Succes)
 */
int main(void)
{
	char lettre;

	lettre = 'z';
	while (lettre >= 'a')
	{
		putchar(lettre);
		lettre--;
	}
	putchar('\n');

	return (0);
}
