#include <stdio.h>

/**
 * main - prints numbers 0 through 99
 * Return: 0
 */
int main(void)
{
int i, j;

i = 48;
j = 48;
while (i < 58)
{
	while (j < 58)
	{
		putchar(i);
		putchar(j);
		j++;
		if (i < 57 || j < 58)
		{
			putchar(',');
			putchar(' ');
		}
	}
	i++;
	j = 48;
}
putchar('\n');
return (0);
}
