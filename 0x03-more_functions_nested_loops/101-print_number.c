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
	char array[100];
	int length = 0;

	if (n == 0)
		_putchar('0');
	else if (n < 0)
	{
		_putchar('-');
		n = -n;
	}

	while (n > 0)
	{
		array[length] = n % 10;
		n /= 10;
		length++;
	}

	while (length > 0)
	{
		_putchar(array[length - 1] + '0');
		length--;
	}
}
