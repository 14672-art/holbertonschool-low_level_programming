#include "main.h"

/**
 * rev_string - Inverse une chaîne de caractères en mémoire.
 * @s: La chaîne de caractères à modifier.
 *
 * Return: void.
 */
void rev_string(char *s)
{
	int start = 0;
	int end = 0;
	char temp;

	/* Trouver la longueur de la chaîne */
	while (s[end] != '\0')
	{
		end++;
	}
	end--; /* On recule de 1 pour pointer sur le dernier caractère */

	/* Échanger les caractères jusqu'au milieu */
	while (start < end)
	{
		temp = s[start];
		s[start] = s[end];
		s[end] = temp;

		start++;
		end--;
	}
}
