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
	int length = 1000000000, negative = 0;

	if (n > 0)
		n = -n;
	else
		negative = 1;


	if (n != 0)
	{
		while (n / length == 0)
		{
			length /= 10;
		}

		if (negative)
			_putchar('-');

		while (length >= 1)
		{
			_putchar(-(n / length) + '0');
			n = n % length;
			length /= 10;
		}
	}
	else
		_putchar(n + '0');
}
