#include "holberton.h"

/**
 * times_table - print the 9 times table, starting at 0.
 *
 * Return: void
 */
void times_table(void)
{
	int i, j, k, num1, num2;

	for (i = 0; i <= 9; i++)
	{
		j = 0;
		for (j = 0; j <= 9; j++)
		{
			k = i * j;
			num1 = k / 10;
			num2 = k % 10;
			if (num1 > 0)
			{
				if (j > 0)
					_putchar(' ');
				_putchar(num1 + '0');
				_putchar(num2 + '0');
			}
			else
			{
				if (j > 0)
				{
					_putchar(' ');
					_putchar(' ');
				}
				_putchar(num2 + '0');
			}
			if (j < 9)
				_putchar(',');
		}
		_putchar('\n');
	}
}
