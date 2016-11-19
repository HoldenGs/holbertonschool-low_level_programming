#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_strings - print string arguments, followed by a newline
 * @separator: string to print between argument strings
 * @n: number of strings
 *
 * Return: void
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	unsigned int i;
	va_list list;
	char *s;

	va_start(list, n);
	for (i = 0; i < n; i++)
	{
		s = va_arg(list, char *);
		if (separator == NULL)
			printf("%s", s);
		else
		{
			if (s == NULL)
				printf("(nil)");
			else
				printf("%s", s);
			if (i + 1 < n)
				printf("%s", separator);
		}
	}
	putchar('\n');
}
