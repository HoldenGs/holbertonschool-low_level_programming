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
if ((i < k || (i == k && l > j)) && !(i == l && j == k))
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
l = 48;
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
