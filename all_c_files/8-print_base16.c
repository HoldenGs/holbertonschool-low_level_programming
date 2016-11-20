#include <stdio.h>

/**
 * main - print all numbers of base 16 in lowercase, followed by a newline
 * Return: 0
 */
int main(void)
{
int i, j;

i = 48;
j = 97;
while (i < 58)
{
	putchar(i);
	i++;
}
while (j < 103)
{
	putchar(j);
	j++;
}
putchar('\n');
return (0);
}
