#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_numbers - print numbers, followed by a newline
 * @separator: string to print between numbers
 * @n: number of integer parameters
 *
 * Return: void
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	unsigned int i;
	va_list list;

	va_start(list, n);
	for (i = 0; i < n; i++)
	{
		if (separator == NULL)
			printf("%d", va_arg(list, int));
		else
		{
			printf("%d", va_arg(list, int));
			if (i + 1 < n)
				printf("%s", separator);
		}
	}
	printf("\n");
}
