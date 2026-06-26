#include <stdio.h>

/**
 * main - Point d'entree du programme
 *
 * Description: Affiche l'alphabet en minuscules sauf q et e.
 * Return: Toujours 0 (Succes)
 */
int main(void)
{
	char lettre;

	lettre = 'a';
	while (lettre <= 'z')
	{
		if (lettre != 'e' && lettre != 'q')
		{
			putchar(lettre);
		}
		lettre++;
	}

	putchar('\n');

	return (0);
}
