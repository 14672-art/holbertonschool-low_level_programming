#include <stdio.h>

/**
 * sum_to_n - Calcule la somme de tous les entiers de 1 à n.
 * @n: La limite supérieure de la somme.
 *
 * Return: La somme totale.
 */
int sum_to_n(int n)
{
	int i;
	int sum = 0;

	for (i = 1; i <= n; i++)
		sum += i;

	return (sum);
}

/* -- DO NOT Modify the code below this line -- */
int main(void)
{
	printf("%d\n", sum_to_n(10));
	return (0);
}
