#include <stdio.h>
#include "holberton.h"

unsigned long int cut(unsigned long int num, int digit);
unsigned long int power(int base, int exp);
/**
 * main - find and compute the first 98 Fibonacci numbers, starting at 1, 2
 *
 * Description: At 89th number, begin counting using two variables
 *
 * Return: 0
 */
int main(void)
{
	unsigned long int first, second, next;
	int first2, second2, next2, i;

	first = i = 1;
	second = 2;
	next = 3;

	printf("%lu, %lu, ", first, second);
	for (i = 0; i < 95; i++)
	{
	if (i >= 88)
	{
		next2 += cut(next, 18);
		next %= power(10, 18);

		printf("%d", next2);

		first2 = second2;
		second2 = next2;
		next2 = first2 + second2;
	}
	if (i < 94)
		printf("%lu, ", next);
	else
		printf("%lu\n", next);

	first = second;
	second = next;
	next = first + second;
}
	return (0);
}


/**
 * cut - cut integer @num down by @digit places
 *
 * Description: divides @num by the power of @digit
 * @num: number to cut
 * @digit: number of digits to cut
 * Return: @num after having @digit places cut
 */
unsigned long int cut(unsigned long int num, int digit)
{
	return (num / power(10, digit));
}


/**
 * power - return power of a number
 *
 * Description: Multiply @base @exp number of times
 * @base: base number
 * @exp: exponent
 * Return: 0
 */
unsigned long int power(int base, int exp)
{
	unsigned long int result = 1;

	while (exp > 0)
	{
		result *= base;
		exp--;
	}
	return (result);

}
