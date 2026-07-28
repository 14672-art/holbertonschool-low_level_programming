#include <stdio.h>

/**
 * main - Simple calculator program handling standard arithmetic operations.
 *
 * Description: Supports addition (1), subtraction (2), multiplication (3),
 * and division (4) using floating-point values for consistent decimal
 * operations across all choices. Choice 0 exits the program.
 *
 * Return: Always 0 (Success).
 */
int main(void)
{
	int choice;
	double a, b;

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

		if (choice >= 1 && choice <= 4)
		{
			printf("A: ");
			if (scanf("%lf", &a) != 1)
				break;
			printf("B: ");
			if (scanf("%lf", &b) != 1)
				break;

			if (choice == 1)
				printf("Result: %g\n", a + b);
			else if (choice == 2)
				printf("Result: %g\n", a - b);
			else if (choice == 3)
				printf("Result: %g\n", a * b);
			else if (choice == 4)
			{
				if (b == 0)
					printf("Error: division by zero\n");
				else
					printf("Result: %g\n", a / b);
			}
		}
		else
		{
			printf("Invalid choice\n");
		}
	}

	return (0);
}

