#include "holberton.h"

/**
 * is_prime_number - checks if @n is a prime number
 *
 * @n: number being checked
 *
 * Return: 1 if @n is prime, otherwise 0
 */
int is_prime_number(int n)
{
	if (n <= 1)
		return (0);
	return (is_prime_helper(n, 2));
}

/**
 * is_prime_helper - helps check primes
 *
 * @n: number being checked
 * @check: iterator checking for divisibility into @n
 *
 * Return: 1 if @n is prime, otherwise 0
 */
int is_prime_helper(int n, int check)
{
	if (n % check == 0)
		return (0);
	else if (check * check >= n)
		return (1);
	return (is_prime_helper(n, check + 1));
}
