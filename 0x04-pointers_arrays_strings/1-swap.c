#include "holberton.h"

/**
 * swap_int - swap the values at addresses @a and @b
 *
 * @a: address to value to swap with @b
 *
 * @b: address to value to swap with @a
 *
 * Return: void
 */
void swap_int(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
