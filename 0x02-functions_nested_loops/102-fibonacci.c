#include <stdio.h>

/**
 * main - print first 50 Fibonacci numbers, followed by a newline
 *
 * Return: 0
 */
int main(void)
{
	int i, first = 1, second = 2, next;

	printf("%d, %d, ", first, second);
	for (i = 0; i < 51; i++)
	{
		next = first + second;
		first = second;
		second = next;
		if (i < 50)
			printf("%d, ", next);
		else
			printf("%d\n", next);
	}
	return (0);
}
