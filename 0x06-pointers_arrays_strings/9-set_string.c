#include "holberton.h"

/**
 * set_string - set the value of a pointer to a char
 *
 * @s: pointer to point to a pointer
 * @to: pointer to char
 *
 * Return: value of double pointer @s
 */
void set_string(char **s, char *to)
{
	*s = to;
}
