#include <stdio.h>

/**
 * main - compute and print the sum of all multiples of 3 or 5 below 1024,
 * followed by a newline.
 *
 * Return: void.
 */
int main(void)
{
	int i, sum;

	sum = 0;
	for (i = 0; i < 1024; i++)
	{
		if (i % 5 == 0 || i % 3 == 0)
		{
			sum += i;
		}
	}
	printf("%d\n", sum);
	return (0);
}
