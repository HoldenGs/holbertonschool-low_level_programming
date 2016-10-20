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
	long array[100000], length = 0, ln = n;

	if (ln == 0)
		_putchar('0');
	else if (ln < 0)
	{
		_putchar('-');
		ln = -ln;
	}

	while (ln > 0)
	{
		array[length] = ln % 10;
		ln /= 10;
		length++;
	}

	while (length > 0)
	{
		_putchar(array[length - 1] + '0');
		length--;
	}
}
