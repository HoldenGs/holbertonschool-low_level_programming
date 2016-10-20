#include <stdio.h>

/**
 * main - print first 50 Fibonacci numbers, followed by a newline
 *
 * Return: 0
 */
int main(void)
{
	long i, first = 1, second = 2, next;

	printf("%ld, %ld, ", first, second);
	for (i = 0; i < 48; i++)
	{
		next = first + second;
		first = second;
		second = next;
		if (i < 47)
			printf("%ld, ", next);
		else
			printf("%ld\n", next);
	}
	return (0);
}
