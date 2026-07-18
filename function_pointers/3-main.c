#include "3-calc.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - Programme qui effectue des opérations simples.
 * @argc: Le nombre d'arguments.
 * @argv: Le tableau des arguments.
 *
 * Return: 0 en cas de succès.
 */
int main(int argc, char *argv[])
{
	int num1, num2;
	int (*func)(int, int);

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	num1 = atoi(argv[1]);
	num2 = atoi(argv[3]);

	func = get_op_func(argv[2]);

	if (func == NULL)
	{
		printf("Error\n");
		exit(99);
	}

	printf("%d\n", func(num1, num2));

	return (0);
}
