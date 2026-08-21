#include "main.h"

int _sqrt_helper(int n, int i);

/**
 * _sqrt_recursion - Returns the natural square root of a number.
 * @n: The number to find the square root of.
 *
 * Return: The natural square root, or -1 if n does not have one.
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
	{
		return (-1);
	}
	return (_sqrt_helper(n, 0));
}

/**
 * _sqrt_helper - Recurses to find the natural square root of a number.
 * @n: The number to find the square root of.
 * @i: The current iterator/guess to test.
 *
 * Return: The square root if found, or -1 if no natural root exists.
 */
int _sqrt_helper(int n, int i)
{
	if (i * i > n)
	{
		return (-1);
	}
	if (i * i == n)
	{
		return (i);
	}
	return (_sqrt_helper(n, i + 1));
}
