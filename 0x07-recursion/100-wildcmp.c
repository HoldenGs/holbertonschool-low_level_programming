#include "holberton.h"

/**
 * wildcmp - compares two different strings, returning 1 if they are identical
 *
 * @s1: string 1 to compare
 * @s2: string 2 to compare
 *
 * Return: 1 if the strings are identical, otherwise 0
 */
int wildcmp(char *s1, char *s2)
{
	int s1length, s2length;

	s1length = _strlen_recursion(s1);
	s2length = _strlen_recursion(s2);

	return (cmp_helper(s1, s2, s1length, s2length));
}

/**
 * cmp_helper - help wildcmp compare strings
 *
 * @s1: string 1 to compare
 * @s2: string 2 to compare
 * @s1length: reverse position in @s1
 * @s2length: reverse position in @s2
 *
 * Return: 1 if @s1 and @s2 can be considered identical, otherwise 0
 */
int cmp_helper(char *s1, char *s2, int s1length, int s2length)
{
	if (*s2 == '*' && *(s2 + 1) == '\0')
		return (1);
	else if (*s2 == '*')
		return (cmp_helper(s1, s2 + 1, s1length, s2length - 1));
        else if (*(s2 - 1) == '*' && s1length > s2length)
                return (cmp_helper(s1 + 1, s2, s1length - 1, s2length));

	else if (*s1 != *s2)
		return (0);
	else if (*s1 == '\0' && *s2 == '\0')
		return (1);

	else
		return (cmp_helper(s1 + 1, s2 + 1, s1length - 1, s2length - 1));
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
