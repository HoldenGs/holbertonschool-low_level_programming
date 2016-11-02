#include "holberton.h"

/**
 * _sqrt_recursion - return the natural square root of a number
 *
 * @n: integer number to square root
 *
 * Return: square root of @n, or -1 if @n has no natural square root
 */
int _sqrt_recursion(int n)
{
        if (n <= 0)
                return (-1);
        return (recurse_root(n, 1));
}

/**
 * recurse_root - helper function for finding a square root
 *
 * @n: integer number to find the root of
 * @prev: number to aid in recursively finding the root of @n
 *
 * Return: square root of @n
 */
int recurse_root(int n, int prev)
{
        if (n - prev * prev == 0)
                return (prev);
        if (n - prev * prev < 0)
                return (-1);
        return (recurse_root(n, prev + 1));
}
