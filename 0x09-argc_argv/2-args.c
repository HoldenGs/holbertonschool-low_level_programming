#include <stdio.h>
#include "holberton.h"

/**
 * main - print all of the arguments passed
 *
 * @argc: number of arguments
 * @argv: pointer array of arguments
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
	while (argc--)
	{
		printf("%s\n", *argv++);
	}
	return (0);
}
