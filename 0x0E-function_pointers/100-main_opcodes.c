#include <stdio.h>
#include <stdlib.h>

/**
 * main - print main function's opcodes
 * @argc: number of arguments
 * @argv: pointer array of arguments
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
	int i, n;
	unsigned char *p;

	p = (unsigned char *)main;
	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}
	n = atoi(argv[1]);
	if (n < 0)
	{
		printf("Error\n");
		exit(2);
	}

	for (i = 0; i < n; i++)
	{
		if ((i + 1) < n)
			printf("%02x ", *(p + i));
		else
			printf("%02x\n", *(p + i));
	}
	return (0);
}
