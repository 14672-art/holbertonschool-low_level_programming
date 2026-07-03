#include "main.h"

/**
 * cap_string - Modifie la casse des premieres lettres
 * @s: La chaine
 * Return: char pointer
 */
char *cap_string(char *s)
{
	int index = 0;

	while (s[index] != '\0')
	{
		if (s[index] >= 'a' && s[index] <= 'z')
		{
			if (index == 0 ||
			    s[index - 1] == ' ' || s[index - 1] == '\t' ||
			    s[index - 1] == '\n' || s[index - 1] == ',' ||
			    s[index - 1] == ';' || s[index - 1] == '.' ||
			    s[index - 1] == '!' || s[index - 1] == '?' ||
			    s[index - 1] == '"' || s[index - 1] == '(' ||
			    s[index - 1] == ')' || s[index - 1] == '{' ||
			    s[index - 1] == '}')
			{
				s[index] = s[index] - 32;
			}
		}
		index++;
	}

	return (s);
}
