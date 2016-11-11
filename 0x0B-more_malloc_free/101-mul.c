#include <stdio.h>
#include <stdlib.h>
#include "holberton.h"

/**
 * main - print out the product of two argument integers
 *
 * @argc: number of arguments
 * @argv: pointer array of arguments
 *
 * Return: 0; 98 if error
 */
int main(int argc, char *argv[])
{
	char *error = "Error\n", *product;
	int length1, length2;

	if (argc != 3)
	{
		_puts(error);
		exit(98);
	}

	length1 = digit_length(argv[1]);
	length2 = digit_length(argv[2]);

	if (length1 == 0 || length2 == 0)
	{
		_puts(error);
		exit(98);
	}

	product = mul(argv[1], argv[2], length1, length2);

	printf("%s\n", product);

	return (0);

	/* aproduct = atoi(product); */

	/* puts(aproduct); */
}

/**
 * mul - multiply two numbers @a and @b
 *
 * @a: first number
 * @b: second number
 * @length1: length of first number
 * @length2: length of second number
 *
 * Return: pointer to array of product
 */
char *mul(char *a, char *b, int length1, int length2)
{
	int i, j, num, prvrmndr, size;
	char *product;

	size = length1 + length2;
	product = malloc((size) * sizeof(char));
	if (product == NULL)
		return (NULL);
	size--;

	for (i = length1 - 1; i >= 0; i--)
	{
		putchar('a');
		for (j = length2 - 1; j >= 0; j--)
		{
			putchar('b');
			prvrmndr = product[size];
			num = (((b[j] - '0') * (a[i] - '0') + product[size]) % 10) + '0';
			product[size] = num;
			product[size - 1] = (((a[i] - '0') * (b[j] - '0') + prvrmndr) / 10);
			size--;
		}
	}
	product[size] = product[size] + '0';
	product[length1 + length2] = '\0';

	return (product);
}

/**
 * _puts - print out a string
 *
 * @s: string
 *
 * Return: void
 */
void _puts(char *s)
{
	int i;

	for (i = 0; i < 6; i++)
		_putchar(s[i]);
}

/**
 * digit_length - count the digits in @n
 *
 * @n: pointer to number
 *
 * Return: length of digit; NULL if @n contains a non-integer
 */
int digit_length(char *n)
{
	int i;

	for (i = 0; n[i] != 0; i++)
	{
		if (n[i] < '0' || n[i] > '9')
			return (0);
	}
	return (i);
}
