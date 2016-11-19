#include "variadic_functions.h"
#include <stdarg.h>

/**
 * sum_them_all - return the sum of its parameters
 * @n: number of parameters
 *
 * Return: sum of its parameters
 */
int sum_them_all(const unsigned int n, ...)
{
	unsigned int i, sum;
	va_list list;

	if (n == 0)
		return (0);

	sum = 0;
	va_start(list, n);
	for (i = 0; i < n; i++)
	{
		sum += va_arg(list, int);
	}

	return (sum);
}
