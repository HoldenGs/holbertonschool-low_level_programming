#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

/**
 * main - check the code for Holberton School students
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

	a = atoi(argv[1]);
	b = atoi(argv[3]);
	n = (*get_op_func(argv[2]))(a, b);

	printf("%d\n", n);
	return (0);
}
