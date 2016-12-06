#include "holberton.h"

/**
 * print_binary - print a number's binary equivalent
 * @n: number
 *
 * Return: void
 */
void print_binary(unsigned long int n)
{
	unsigned long int multiplier;
	int i;

	multiplier = i = 1;
	while (multiplier <= n && i < 64)
	{
		i++;
		multiplier <<= 1;
	}
	multiplier >>= 1;
	while (multiplier > 0)
	{
		if (multiplier & n)
			_putchar('1');
		else
			_putchar('0');
		multiplier >>= 1;
	}
	if (n == 0)
		_putchar('0');
}
