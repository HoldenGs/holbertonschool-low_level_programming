#include <stdio.h>

/**
 * main - prints all numbers of base 10 followed by a newline
 * Return: 0
 */
int main(void)
{
int i;

i = 48;
while (i < 58)
{
	putchar(i);
	i++;
}
putchar('\n');
return (0);
}
