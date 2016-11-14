#include <stdio.h>

/**
 * main - print out the name of the file using a macro
 *
 * Return: 0
 */
int main(void)
{
	printf("%s\n", __BASE_FILE__);
	return (0);
}
