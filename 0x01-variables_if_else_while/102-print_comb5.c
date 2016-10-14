#include <stdio.h>

/**
 * main - print all possible combinations of two two-digit numbers
 * Return: 0
 */
int main(void)
{
int i, j, k, l;

i = j = k = l = 48;

while (i < 58)
{
while (j < 58)
{
while (k < 58)
{
while (l < 58)
{
if ((i + j) < (k + l))
{
putchar(i);
putchar(j);
putchar(' ');
putchar(k);
putchar(l);
if (i < 57 || j < 56)
{
putchar(',');
putchar(' ');
}
}
l++;
}
k++;
l = 48;
}
j++;
k = 48;
}
i++;
j = 48;
}
putchar('\n');
return (0);
}
