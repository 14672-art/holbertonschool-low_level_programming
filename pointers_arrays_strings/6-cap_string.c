#include "main.h"

/**
 * is_separator - Vérifie si un caractère est un séparateur de mots.
 * @c: Le caractère à tester.
 *
 * Return: 1 si c'est un séparateur, 0 sinon.
 */
int is_separator(char c)
{
	char separators[] = " \t\n,;.!?\"(){}";
	int i = 0;

	while (separators[i] != '\0')
	{
		if (c == separators[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}

/**
 * cap_string - Met en majuscule la première lettre de chaque mot.
 * @str: La chaîne de caractères à modifier.
 *
 * Return: Un pointeur vers la chaîne modifiée.
 */
char *cap_string(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		/* Si c'est le premier caractère et qu'il est minuscule */
		if (i == 0 && (str[i] >= 'a' && str[i] <= 'z'))
		{
			str[i] = str[i] - 32;
		}
		/* Si le caractère précédent est un séparateur et l'actuel est minuscule */
		else if (is_separator(str[i - 1]) && (str[i] >= 'a' && str[i] <= 'z'))
		{
			str[i] = str[i] - 32;
		}
		i++;
	}

	return (str);
}
