#include <stdio.h>

/**
 * main - Point d'entree du programme
 *
 * Description: Affiche tous les nombres de la base 16 en minuscules.
 * Return: Toujours 0 (Succes)
 */
int main(void)
{
	char caractere;

	/* Boucle pour les chiffres de 0 a 9 */
	caractere = '0';
	while (caractere <= '9')
	{
		putchar(caractere);
		caractere++;
	}

	/* Boucle pour les lettres de a a f */
	caractere = 'a';
	while (caractere <= 'f')
	{
		putchar(caractere);
		caractere++;
	}

	putchar('\n');

	return (0);
}
