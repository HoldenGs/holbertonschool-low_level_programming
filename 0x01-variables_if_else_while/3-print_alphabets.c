#include <stdio.h>

/**
 * main - print alphabet in lowercase, then uppercase, followed by a newline
 * Return: 0
 */
int main(void)
{
int i, j;

i = 97;
j = 65;
while (i < 123)
{
putchar(i);
i++;
}

while (j < 91)
{
putchar(j);
j++;
}
putchar('\n');
return (0);
}
