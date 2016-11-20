#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_all - print anything
 * @format: string pointer denoting each argument type
 *
 * Return: void
 */
void print_all(const char * const format, ...)
{
	int i;
	char *s;
	va_list list;

	i = 0;
	va_start(list, format);
	while (format[i] != 0)
	{
		switch (format[i])
		{
		case 'c':
			printf("%c", va_arg(list, int));
			break;
		case 'i':
			printf("%i", va_arg(list, int));
			break;
		case 'f':
			printf("%f", va_arg(list, double));
			break;
		case 's':
			s = va_arg(list, char *);
			if (s == NULL)
			{
				printf("(nil)");
				break;
			}
			printf("%s", s);
		}

		if ((format[i] == 'c' || format[i] == 'i' || format[i] == 'f' ||
		     format[i] == 's') && format[i + 1] != 0)
			printf(", ");
		i++;
	}
	putchar('\n');
}
