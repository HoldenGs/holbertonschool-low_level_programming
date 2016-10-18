#include "holberton.h"

/**
 * jack_bauer - print every minute of the day, Jack Bauer-style
 *
 * Return: void
 */
void jack_bauer(void)
{
	int i, j, k, l;

	for (i = 0; i < 3; i++)
	{
		j = 0;
		for (j = 0; j <= 9; j++)
		{
			k = 0;
			for (k = 0; k < 6; k++)
			{
				l = 0;
				for (l = 0; l <= 9; l++)
				{
					if (i < 2 || (i == 2 && j < 4))
						{
							_putchar(i + '0');
							_putchar(j + '0');
							_putchar(':');
							_putchar(k + '0');
							_putchar(l + '0');
							_putchar('\n');
						}
				}
			}
		}
	}
}
