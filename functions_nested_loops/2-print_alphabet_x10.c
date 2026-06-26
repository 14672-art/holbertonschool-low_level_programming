#include "main.h"

/**
 * print_alphabet_x10 - Affiche 10 fois l'alphabet en minuscules
 *
 * Description: Utilise des boucles imbriquees pour repeter l'alphabet
 * 10 fois, chaque repetition etant suivie d'une nouvelle ligne.
 */
void print_alphabet_x10(void)
{
	int i;
	char letter;

	for (i = 0; i < 10; i++)
	{
		for (letter = 'a'; letter <= 'z'; letter++)
		{
			_putchar(letter);
		}
		_putchar('\n');
	}
}
