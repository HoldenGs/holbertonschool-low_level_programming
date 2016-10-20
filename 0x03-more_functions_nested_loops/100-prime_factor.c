#include <stdio.h>

/**
 * main - compute and print the largest prime factor of 612852475143
 *
 * Return: 0
 */
int main(void)
{
	long num = 612852475143, divisor = 2, bigprime = 0;

	while (num > 1)
	{
		if (num % divisor == 0)
		{
			bigprime = divisor;
			num /= divisor;
			divisor = 2;
		}
		else
			divisor++;
	}

	printf("%ld\n", bigprime);
	return (0);
}
