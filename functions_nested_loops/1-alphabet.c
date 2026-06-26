#include "main.h"

/**
 * print_alphabet - Affiche l'alphabet en minuscules
 *
 * Description: Utilise une boucle pour parcourir les caracteres de a a z
 * et se termine par un retour a la ligne.
 */
void print_alphabet(void)
{
	char letter;

	for (letter = 'a'; letter <= 'z'; letter++)
	{
		_putchar(letter);
	}
	_putchar('\n');
}
