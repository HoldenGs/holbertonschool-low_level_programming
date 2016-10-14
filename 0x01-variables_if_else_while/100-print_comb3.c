#include <stdio.h>

/**
 * main prints all unique combinations of two digits
 * Return: 0
 */
int main(void)
{
int i, j;

i = j = 48;

while (i < 58)
{
while (j < 58)
{
if (j > i)
{
putchar(i);
putchar(j);
if (i < 56)
{
putchar(',');
putchar(' ');
}
}
j++;
}
i++;
j = 48;
}
putchar('\n');
return (0);
}
