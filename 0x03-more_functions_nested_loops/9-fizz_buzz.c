#include <stdio.h>

/**
 * main - print an output that passes the Fizz-Buzz test
 *
 * Description: print numbers 1-100, followed by a newline.
 * If a number is a multiple of 3, print Fizz instead.
 * If a number is a multiple of 5, print Buzz instead.
 * If a number is both, print FizzBuzz instead.
 *
 * Return: 0
 */
int main(void)
{
	int i;

	for (i = 1; i < 101; i++)
	{
		if (i % 3 == 0 && i % 5 == 0)
			printf("FizzBuzz ");
		else if (i % 3 == 0)
			printf("Fizz ");
		else if (i % 5 == 0)
			if (i > 99)
				printf("Buzz");
			else
				printf("Buzz ");
		else
			printf("%d ", i);
	}
	putchar('\n');
	return (0);
}
