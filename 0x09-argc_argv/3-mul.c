#include <stdio.h>
#include <stdlib.h>
#include "holberton.h"

/**
 * main - print the product of two integer arguments
 *
 * @argc: number of arguments
 * @argv: pointer array of arguments
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
	int answer;

	answer = atoi(argv[1]) * atoi(argv[2]);
	if (argc == 3)
	{
		printf("%d\n", answer);
		return (0);
	}
	else
	{
		printf("Error");
		return (1);
	}
}
