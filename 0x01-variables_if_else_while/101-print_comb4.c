#include <stdio.h>

/**
 * main - prints all possible unique combinations of 3 digits
 * Return: 0
 */
int main(void)
{
int i, j, k;

i = j = k = 48;

while (i < 58)
{
while (j < 58)
{
while (k < 58)
{
if (k > j && j > i)
{
putchar(i);
putchar(j);
putchar(k);
if (i < 55)
{
putchar(',');
putchar(' ');
}
}
k++;
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
