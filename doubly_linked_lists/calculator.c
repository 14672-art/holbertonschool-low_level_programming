#include <stdio.h>

/**
 * main - Entree du programme de calculatrice simple
 *
 * Return: Toujours 0 (Succes)
 */
int main(void)
{
	int choice;

	while (1)
	{
		printf("Choice: ");
		if (scanf("%d", &choice) != 1)
			break;

		if (choice == 0)
		{
			printf("Bye!\n");
			break;
		}

		if (choice < 1 || choice > 4)
		{
			printf("Invalid choice\n");
			continue;
		}

		/* Le code pour les opérations (1 à 4) viendra ici */
	}

	return (0);
}
