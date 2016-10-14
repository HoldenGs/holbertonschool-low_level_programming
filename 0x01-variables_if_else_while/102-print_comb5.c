#include <stdio.h>

/**
 * main - print all possible combinations of two two-digit numbers
 * Return: 0
 */
int main(void)
{
int num1, num2, num3, num4, i, j;

for (i = 0; i < 100; i++)
{
	num1 = i / 10;
	num2 = i % 10;
	for (j = 0; j < 100; j++)
	{
		num3 = j / 10;
		num4 = j % 10;
		if (j > i || (num1 == num3 && num3 < num4))
		{
			putchar(num1 + '0');
			putchar(num2 + '0');
			putchar(' ');
       			putchar(num3 + '0');
			putchar(num4 + '0');
			if (i < 98)
			{
				putchar(',');
				putchar(' ');
			}
		}
	}
}
putchar('\n');
return (0);
}
