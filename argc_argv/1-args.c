#include <stdio.h>

/**
 * main - Affiche le nombre d'arguments passés au programme.
 * @argc: Le nombre d'arguments.
 * @argv: Le tableau des arguments (inutilisé).
 *
 * Return: Toujours 0 (Succès).
 */
int main(int argc, char *argv[] __attribute__((unused)))
{
	printf("%d\n", argc - 1);
	return (0);
}
