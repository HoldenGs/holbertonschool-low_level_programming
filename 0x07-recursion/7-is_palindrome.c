#include "holberton.h"

/**
 * is_palindrome - checks if string is a palindrome
 *
 * @s: string being checked
 *
 * Return: 1 if @s is a palindrome, otherwise 0
 */
int is_palindrome(char *s)
{
	int length;

	length = _strlen_recursion(*s);
	return (palindrome_helper(*s, length));
}

/**
 * palindrome_helper - helps is_palindrome
 *
 * @s: string being analyzed
 * @length: length in string
 *
 * Return: 1 if @s is a palindrome, otherwise 0
 */
int palindrome_helper(char *s, int length)
{

}
