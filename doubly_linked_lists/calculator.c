#include <stdio.h>

/**
 * main - Entree du programme de calculatrice simple
 *
 * Return: Toujours 0 (Succes)
 */
int main(void)
{
	int choice;
	int a, b;

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

		if (choice == 1)
		{
			printf("A: ");
			scanf("%d", &a);
			printf("B: ");
			scanf("%d", &b);
			printf("Result: %d\n", a + b);
		}
		else if (choice == 2)
		{
			printf("A: ");
			scanf("%d", &a);
			printf("B: ");
			scanf("%d", &b);
			printf("Result: %d\n", a - b);
		}
		else
		{
			printf("Invalid choice\n");
		}
	}

	return (0);
}
