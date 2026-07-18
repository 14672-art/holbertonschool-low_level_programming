#include <stdio.h>

/**
 * main - Affiche le nom du programme suivi d'une nouvelle ligne.
 * @argc: Le nombre d'arguments (inutilisé).
 * @argv: Le tableau des arguments de la ligne de commande.
 *
 * Return: Toujours 0 (Succès).
 */
int main(int argc __attribute__((unused)), char *argv[])
{
	printf("%s\n", argv[0]);
	return (0);
}
