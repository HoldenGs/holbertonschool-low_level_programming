#include "holberton.h"
#include <stdio.h>

/**
 * print_to_98 - print all natural numbers from @n to 98, followed by a newline
 *
 * @n: number from which to count to 98
 *
 * Return: void
 */
void print_to_98(int n)
{
	int i;

	if (n <= 98)
	{
		for (i = n; i < 99; i++)
		{
			if (i < 98)
				printf("%d, ", i);
			else
				printf("%d\n", i);
		}
	}
	else if (n > 98)
	{
		for (i = n; i > 97; i--)
		{
			if (i > 98)
				printf("%d, ", i);
			else
				printf("%d\n", i);
		}
	}
}
