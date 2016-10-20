#include <stdio.h>

/**
 * main - print sum of even values not exceeding 4,000,000 in the
 * Fibonacci sequence
 *
 * Return: 0
 */
int main(void)
{
	long sum, first = 1, second = 2, next;

	sum = 2;
	while (next < 4000000)
	{
		next = first + second;
		first = second;
		second = next;
		if (next % 2 == 0)
			sum += next;
	}
	printf("%ld\n", sum);
	return (0);
}
