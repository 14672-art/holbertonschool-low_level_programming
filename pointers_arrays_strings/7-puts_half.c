#include "main.h"

/**
 * puts_half - Affiche la seconde moitié d'une chaîne.
 * @str: La chaîne de caractères à traiter.
 *
 * Return: void.
 */
void puts_half(char *str)
{
	int length = 0;
	int start;

	/* 1. Trouver la longueur de la chaîne */
	while (str[length] != '\0')
	{
		length++;
	}

	/* 2. Déterminer l'index de départ selon la parité */
	if (length % 2 == 0)
	{
		start = length / 2;
	}
	else
	{
		/* Équivaut à la formule (length + 1) / 2 pour le nombre de chars */
		start = (length + 1) / 2;
	}

	/* 3. Afficher les caractères de l'index 'start' jusqu'à la fin */
	while (str[start] != '\0')
	{
		_putchar(str[start]);
		start++;
	}

	_putchar('\n');
}
