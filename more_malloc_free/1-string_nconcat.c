#include "main.h"
#include <stdlib.h>

/**
 * string_nconcat - Concatenates two strings up to n bytes of s2.
 * @s1: The first string.
 * @s2: The second string.
 * @n: The maximum number of bytes of s2 to concatenate.
 *
 * Return: A pointer to the newly allocated space in memory,
 * or NULL if the function fails.
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *concat;
	unsigned int len1 = 0, len2 = 0, i, j;

	/* Si les chaînes sont NULL, on les traite comme des chaînes vides */
	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	/* Calcul des longueurs de s1 et s2 */
	while (s1[len1] != '\0')
		len1++;
	while (s2[len2] != '\0')
		len2++;

	/* Si n est supérieur ou égal à la longueur de s2, on prend tout s2 */
	if (n >= len2)
		n = len2;

	/* Allocation : taille s1 + les n octets de s2 + 1 pour le '\0' */
	concat = malloc(sizeof(char) * (len1 + n + 1));

	if (concat == NULL)
		return (NULL);

	/* Copie de s1 dans le nouvel espace */
	for (i = 0; i < len1; i++)
		concat[i] = s1[i];

	/* Ajout des n octets de s2 à la suite */
	for (j = 0; j < n; j++, i++)
		concat[i] = s2[j];

	/* Ajout du caractère de fin de chaîne obligatoire */
	concat[i] = '\0';

	return (concat);
}
