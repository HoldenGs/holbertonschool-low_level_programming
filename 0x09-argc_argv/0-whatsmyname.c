#include "holberton.h"
#include <stdio.h>

/**
 * main - print out the name of the program
 *
 * argc: number of arguments
 * argv: array of pointers to program name
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
	if (argc > 0)
		printf("%s\n", argv[0]);
	return (0);
}
