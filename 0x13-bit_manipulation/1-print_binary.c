#include "holberton.h"

/**
 * print_binary - print a number's binary equivalent
 * @n: number
 *
 * Return: void
 */
void print_binary(unsigned long int n)
{
	int bitshift;
	unsigned long int tmp;
	char c, flag;

	flag = 0;
	bitshift = sizeof(unsigned long int) * 8 - 1;
	while (bitshift >= 0)
	{
		tmp = n >> bitshift;
		c = tmp & 1;
		if (flag == 1 && c == 0)
			_putchar ('0');
		else if (c == 1)
		{
			flag = 1;
			_putchar ('1');
		}
		bitshift--;
	}
}
