#include "holberton.h"

/**
 * print_number - print integer @n
 *
 * @n: integer to print
 *
 * Return: void
 */
void print_number(int n)
{
	int length, tmp = n;

	if (n == 0)
		_putchar(n + '0');
	else if (n < 0)
		_putchar('-');

	while (tmp > 0)
	{
		if (tmp % 10 == 0)
		tmp /= 10;
		length++;
	}

	while (n != 0)
	{
		_putchar(n / length + '0');
		length--;
	}
}
