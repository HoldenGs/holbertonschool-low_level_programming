#include <stdio.h>

/**
 * main - print all lowercase letter except 'q' and 'e'
 * Return: 0
 */
int main(void)
{
int i;

i = 97;
while (i < 123)
{
	if (i == 101 || i == 113)
		++i;
	putchar(i);
	i++;
}

putchar('\n');
return (0);
}
