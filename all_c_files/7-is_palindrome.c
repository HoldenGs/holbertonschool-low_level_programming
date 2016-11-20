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

	length = _strlen_recursion(s);
	return (palindrome_helper(s, length - 1, 0));
}

/**
 * palindrome_helper - helps is_palindrome
 *
 * @s: string being analyzed
 * @end: length of string, decrementing to 0
 * @beginning: starts at beginning of string, goes until it hits a 0
 *
 * Return: 1 if @s is a palindrome, otherwise 0
 */
int palindrome_helper(char *s, int end, int beginning)
{
	if (s[beginning] != s[end])
		return (0);
	else if (s[beginning] == '\0')
		return (1);
	return (palindrome_helper(s, end - 1, beginning + 1));
}

/**
 * _strlen_recursion - return the length of a string
 *
 * @s: string to measure
 *
 * Return: int length of string
 */
int _strlen_recursion(char *s)
{
	int length;

	length = 0;
	if (*s == 0)
		return (0);
	return ((length + 1) + _strlen_recursion(s + 1));
}
