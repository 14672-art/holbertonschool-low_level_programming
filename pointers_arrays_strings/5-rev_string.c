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

	/* 1. Trouver la longueur de la chaîne pour positionner 'end' à la fin */
	while (s[end] != '\0')
	{
		end++;
	}
	end--; /* On recule de 1 pour ignorer le '\0' et être sur le dernier caractère */

	/* 2. Échanger les caractères jusqu'au milieu de la chaîne */
	while (start < end)
	{
		temp = s[start];
		s[start] = s[end];
		s[end] = temp;

		start++;
		end--;
	}
}
