#include "holberton.h"

/**
 * factorial - return the factorial of number @n
 *
 * @n: n to begin factorial calculation
 *
 * Return: 0
 */
int factorial(int n)
{
	if (n < 0)
		return (-1);
	if (n == 0)
		return (1);
	return (n * factorial(n - 1));
}
