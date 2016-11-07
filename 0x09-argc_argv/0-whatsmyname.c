#include "holberton.h"
#include <stdio.h>

/**
 * whatsmyname - print out the name of the program
 *
 * argc: number of arguments
 * argv: array of pointers to program name
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
	argc = 1;
	printf("%s\n", argv[argc - 1]);
	return (0);
}
