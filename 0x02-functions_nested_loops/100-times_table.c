#include "holberton.h"

/**
 * print_times_table - prints the @n times table
 *
 * @n: integer number denoting the times table
 *
 * Return: void
 */
void print_times_table(int n)
{
	int i, j;
	if (n == 0)
	{
		_putchar('0');
		_putchar('\n');
	} else if (n < 15 && n > 0)
	{
		for (i = 0; i <= n; i++)
		{
			j = 0;
			for (j = 0; j <= n; j++)
			{
				formatted_print(i, j, n);
			}
			_putchar('\n');
		}
	}
}

/**
 * formatted_print - correctly formats and prints the product of i and j
 *
 * @i: horizontal multiplier
 *
 * @j: vertical multiplicand
 *
 * @n: times table size
 *
 * Return: void
 */
void formatted_print(int i, int j, int n)
{
	int k, num1, num2, num3;

	k = i * j;
	num1 = k / 100;
	num2 = k / 10;
	num3 = k % 10;
	if (j > 0)
	{
		_putchar(' ');
		if (num1 > 0)
		{
			num2 = num2 % 10;
			_putchar(num1 + '0');
			_putchar(num2 + '0');
			_putchar(num3 + '0');
		} else if (num2 > 0)
		{
			_putchar(' ');
			_putchar(num2 + '0');
			_putchar(num3 + '0');
		} else
		{
			_putchar(' ');
			_putchar(' ');
			_putchar(num3 + '0');
		}
		if (j < n)
			_putchar(',');
	} else if (j == 0)
	{
		_putchar('0');
		_putchar(',');
	}
}
