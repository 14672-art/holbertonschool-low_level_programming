#include <stdio.h>
#include <stdlib.h>

/**
 * main - Additionne des nombres positifs.
 * @argc: Le nombre d'arguments.
 * @argv: Le tableau des arguments.
 *
 * Return: 0 si succès, 1 si un argument contient un symbole non-numérique.
 */
int main(int argc, char *argv[])
{
	int i, j;
	int sum = 0;

	for (i = 1; i < argc; i++)
	{
		for (j = 0; argv[i][j] != '\0'; j++)
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
			{
				printf("Error\n");
				return (1);
			}
		}
		sum += atoi(argv[i]);
	}

	printf("%d\n", sum);
	return (0);
}
