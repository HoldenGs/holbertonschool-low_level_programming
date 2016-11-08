#include <stdio.h>
#include <stdlib.h>

/**
 * main - print the minimum number of coins necessary to make change for a
 * given amount of money
 *
 * @argc: number of arguments
 * @argv: pointer array of arguments
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
	int num, sum;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}
	sum = 0;
	num = atoi(argv[1]);

	if (num / 25 > 0)
		sum += num / 25;
	num %= 25;
	if (num / 10 > 0)
		sum += num / 10;
	num %= 10;
	if (num / 5 > 0)
		sum += num / 5;
	num %= 5;
	if (num / 1 > 0)
		sum += num / 1;

	printf("%d\n", sum);
	return (0);
}
