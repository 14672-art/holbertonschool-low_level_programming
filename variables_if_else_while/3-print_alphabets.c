#include <stdio.h>

/**
 * main - Point d'entree du programme
 *
 * Description: Affiche l'alphabet en minuscules, puis en majuscules.
 * Return: Toujours 0 (Succes)
 */
int main(void)
{
	char lettre;

	lettre = 'a';
	while (lettre <= 'z')
	{
		putchar(lettre);
		lettre++;
	}

	lettre = 'A';
	while (lettre <= 'Z')
	{
		putchar(lettre);
		lettre++;
	}

	putchar('\n');

	return (0);
}
