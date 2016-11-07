#include "holberton.h"
#include <stdio.h>

/**
 * main - print the number of arguments, followed by a newline
 *
 * @argc: number of arguments
 * @argv: pointer to array of pointers to arguments
 *
 * Return: 0
 */
int main(int argc, __attribute__ ((unused)) char *argv[])
{
	printf("%d\n", argc - 1);
	return (0);
}
