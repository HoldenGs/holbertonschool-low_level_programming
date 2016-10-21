#include <stdio.h>
#include "holberton.h"

/**
 * main - compute and print the largest prime factor of 612852475143
 *
 * Return: 0
 */
int primefind(void)
{
	long num = 612852475143, divisor = 2;

	while (num > 1)
	{
		if (num % divisor == 0)
		{
			num /= divisor;
		}
		else
			divisor++;
	}

	printf("%ld\n", divisor);
	return (0);
}
