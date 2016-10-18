#include "holberton.h"

/**
 * main - print alphabet in lowercase, followed by a newline
 * Return: 0
 */
void print_alphabet(void)
{
	int i;

	for (i = 0; i < 26; i++)
	{
		_putchar(i + 'a');
	}
	_putchar('\n');
	return;
}
