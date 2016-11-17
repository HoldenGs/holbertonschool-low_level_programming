#include <stdio.h>
#include <stdlib.h>
#include "3-calc.h"

/**
 * main - check the code for Holberton School students
 * @argc: number of arguments
 * @argv: pointer array of arguments
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
	int n, a, b;

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}
	if (argv[2][0] != '+' && argv[2][0] != '-' && argv[2][0] != '*'
	    && argv[2][0] != '/' && argv[2][0] != '%')
	{
		printf("Error\n");
		exit(99);
	}
	if ((argv[2][0] == '/' || argv[2][0] == '%') && argv[3][0] == '0')
	{
		printf("Error\n");
		exit(100);
	}

	a = atoi(argv[1]);
	b = atoi(argv[3]);
	n = (*get_op_func(argv[2]))(a, b);

	printf("%d\n", n);
	return (0);
}
