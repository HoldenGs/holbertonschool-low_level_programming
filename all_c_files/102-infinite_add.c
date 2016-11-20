#include "holberton.h"

void reverse_array(char *c, int n);
int length_of_string(char *b);
/**
 * infinite_add - add two numbers
 *
 * @n1: first number to add
 * @n2: second number to add
 * @r: buffer to store sum
 * @size_r: size of buffer
 *
 * Return: pointer to buffer @r
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int i, j, n = 0, size = 0;

	puts('A');
	i = length_of_string(n1);
	reverse_array(n1, i);
	puts('B');
	j = length_of_string(n2);
	reverse_array(n2, j);


	while (size < size_r)
	{
		r[size] = 0;
		size++;
	}

	while ((n1[n] + n2[n]) && n < size_r)
	{
		if ((n1[n] - '0') + (n2[n] - '0') > 9)
		{
			r[n] = ((n1[n] - '0') + (n2[n] - '0')) % 10 + '0';
			r[n] = ((n1[n] - '0') + (n2[n] - '0')) / 10 + '0';
		}
		else
		{
			r[n] = ((n1[n] - '0') + (n2[n] - '0')) % 10 + '0';
		}
		n++;
	}

	reverse_array(r, n);

	return (r);
}

int length_of_string(char *b)
{
	int i = 0;

	while (b[i])
	{
		i++;
	}
	return (i);
}

void reverse_array(char *c, int n)
{
        int m = 0, p[1000];

        while (n > 0)
        {
                p[m] = c[n - 1];
                n--;
                m++;
        }

        n = 0;
        while (n < m)
        {
                c[n] = p[n];
                n++;
        }
}
