#include <stdio.h>
#include <stdlib.h>

/**
 * main - add integer arguments together and print sum, followed by a newline
 *
 * @argc: number of arguments
 * @argv: pointer array of arguments
 *
 * Return: 1 if there is a non-integer argument, otherwise 0
 */
int main(int argc, char *argv[])
{
	int sum, num, count;

	sum = 0;
	for (count = 1; count < argc; count++)
	{
		num = atoi(argv[count]);
		if (!atoi(argv[count]) || num < 0)
		{
			printf("Error\n");
			return (1);
		}
		else
			sum += num;
	}
	printf("%i\n", sum);
	return (0);
}
