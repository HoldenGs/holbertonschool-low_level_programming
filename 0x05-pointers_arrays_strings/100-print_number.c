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
<<<<<<< HEAD
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
=======
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
>>>>>>> 2072bcd83d112d360e2e604254f30a2acc9de21e
}
