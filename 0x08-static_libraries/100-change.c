#include <stdio.h>

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
	int num, sum, tmpnum;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}
	sum = 0;
	num = atoi(argv[1]);

	if (num / 25 > 0)
	{
		tmpnum = num / 25;
		sum += tmpnum;
		num -= tmpnum * 25;
	}
	if (num / 10 > 0)
	{
		tmpnum = num / 10;
		sum += tmpnum;
		num -= tmpnum * 10;
	}
	if (num / 5 > 0)
	{
		tmpnum = num / 5;
		sum += tmpnum;
		num -= tmpnum * 5;
	}
	if (num / 1 > 0)
	{
		tmpnum = num / 1;
		sum += tmpnum;
	}

	printf("%d\n", sum);
	return (0);
}
