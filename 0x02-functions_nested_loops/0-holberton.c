#include "holberton.h"

/**
 * main - prints the string "Holberton" followed by a newline
 * Return: 0
 */
int main(void)
{
	char string[11] = "Holberton\n";
	int i = 0;

	while (i < 11)
	{
		_putchar(string[i]);
		i++;
	}
	return (0);
}
