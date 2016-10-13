#include <stdio.h>

/**
 * main -  print alphabet backward followed by a newline
 * Return: 0
 */
int main(void)
{
int i;

i = 122;
while (i > 96)
{
	putchar(i);
	i--;
}
putchar('\n');
return (0);
}
