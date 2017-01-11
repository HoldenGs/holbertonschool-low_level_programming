#include "holberton.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _islower - check for a lowercase character
 *
 * @c: the integer to be checked
 * Return: 0
 */
int _islower(int c)
{
	if (c < 'a' || c > 'z')
	   return (0);
	   else
		return (1);
}

/**
 * _isalpha - checks for an alphabetic character
 *
 * @c: integer to be checked
 * Return: 0
 */
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _abs - computes the absolute value of an integer
 *
 * @n: computed integer
 *
 * Return: 0
 */
int _abs(int n)
{
	return (n < 0 ? -n : n);
}

/**
 * _isupper - checks for an uppercase character.
 *
 * @c: character to be checked for case
 *
 * Return: 1 if @c is uppercase; otherwise 0.
 */
int _isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}

/**
 * _isdigit - checks for a digit 0-9
 *
 * @c: character to be checked for digit value
 *
 * Return: 1 if @c is a digit; otherwise 0
 */
int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

/**
 * _strlen - return the length of a string
 *
 * @s: string whose length to return
 *
 * Return: length of @s
 */
int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++);
	return (i);
}

/**
 * _puts - prints a string, followed by a newline, to stdout
 *
 * @str: pointer to the string to print
 */
void _puts(char *str)
{
	int n = 0;

	while (*(str + n) != '\0')
	{
		_putchar(*(str + n));
		n++;
	}
	_putchar('\n');
}

/**
 * *_strcpy - copies @src string to @dest buffer, including '\0'
 *
 * @dest: pointer to buffer for string
 *
 * @src: pointer to string to copy to buffer
 *
 * Return: @dest
 */
char *_strcpy(char *dest, char *src)
{
	int n = 0;

	while (*(src + n))
	{
		*(dest + n) = *(src + n);
		n++;
	}

	n++;
	*(dest + n) = 0;
	return (dest);
}

/**
 * _atoi - convert a string to an integer
 *
 * @s: pointer to a string to parse
 *
 * Return: @s
 */
int _atoi(char *s)
{
	int new_int = 0, sign = 0, n, on_int = 0;

	for (n = 0; *(s + n) != 0; n++)
	{
		if (*(s + n) == '-')
			sign++;
		if (*(s + n) >= '0' && *(s + n) <= '9')
		{
			on_int = 1;
			new_int = new_int * 10 - (*(s + n) - '0');
		}
		else if (on_int == 1)
		{
			if (sign % 2 != 0)
				return (new_int);
			else
				return (-new_int);
		}
	}
	if (sign % 2 != 0)
		return (new_int);
	else
		return (-new_int);
}

/**
 * _strncat - concatenate a string with @n bytes from @src to @dest
 *
 * @dest: string receiving concatenation
 *
 * @src: string to concatenate to @dest
 *
 * @n: number of bytes of @src to concatenate
 *
 * Return: pointer to @dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int index = 0, length = 0;

	while (dest[length])
		length++;
	while (index < n && src[index])
	{
		dest[length++] = src[index++];
	}
	return (dest);
}

/**
 * _strcat - concatenates two strings, overwriting the null terminator of @dest
 *
 * @dest: the string receiving concatenation
 *
 * @src: the string concatenating to the end of @dest
 *
 * Return: @dest after concatenation
 */
char *_strcat(char *dest, char *src)
{
	int index = 0, length = 0;

	while (dest[length])
		length++;
	while (src[index])
	{
		dest[length] = src[index];
		length++;
		index++;
	}
	return (dest);
}

/**
 * _strncpy - copy @n bytes of string @src to buffer @dest
 *
 * @dest: pointer to buffer destination
 *
 * @src: string to string to copy over
 *
 * @n: number of bytes of @src to copy
 *
 * Return: pointer to string @dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i = n;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];
	while (i < n)
		dest[i++] = '\0';
	return (dest);
}

/**
 * _strcmp - compare two strings
 *
 * @s1: first string to compare with @s2
 *
 * @s2: second string from which to compare @s1
 *
 * Return: integer value of characters of @s1 minus character number of @s2
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] == s2[i]; i++)
	{
		if (s1[i] == 0)
			return (0);
	}
	return (s1[i] - s2[i]);
}

/**
 * _memset - fill @n bytes of area pointed to by @s with the constant byte @b
 *
 * @s: pointer to buffer
 * @b: constant byte to fill buffer
 * @n: number of bytes of @s to fill with @b
 *
 * Return: a pointer to the memory area @s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}
	return (s);
}

/**
 * _memcpy - copy @n byte from memory area @src to memory area @dest
 *
 * @dest: destination memory area
 * @src: source memory area
 * @n: bytes of memory to copy over
 *
 * Return: pointer to @dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}

/**
 * _strchr - locate a character in a string
 *
 * @s: pointer to string
 * @c: character
 *
 * Return: pointer to first occurrence of @c in @s
 */
char *_strchr(char *s, char c)
{
	int i = 0;

	while (s[i] != 0)
	{
		if (s[i] == c)
			return (s + i);
		i++;
	}

	if (s[i] == c)
		return (s + i);
	return ('\0');
}

/**
 * _strspn - get the length of a prefix substring
 *
 * @s: string to search
 * @accept: substring to compare string with
 *
 * Return: number of bytes in th initial segment of @s which consist of only
 * bytes from @accept
 */
unsigned int _strspn(char *s, char *accept)
{
	int i = 0, j = 0, flag = 0, count = 0;

	while (s[i] && count == i)
	{
		while (accept[j] && !(flag))
		{
			if (accept[j] == s[i])
			{
				count++;
				flag = 1;
			}
			j++;
		}
		j = 0;
		flag = 0;
		i++;
	}
	return (count);
}

/**
 * _strpbrk - search string @s for the first occurance of any bytes of @accept
 *
 * @s: string to search
 * @accept: string to search @s for bytes from
 *
 * Return: a pointer to the byte @s that matches one of the bytes in accept,
 * otherwise NULL
 */
char *_strpbrk(char *s, char *accept)
{
	int i = 0, j = 0;

	while (s[i])
	{
		j = 0;
		while (accept[j])
		{
			if (accept[j] == s[i])
				return (s + i);
			j++;
		}
		i++;
	}
	return ('\0');
}


/**
 * _strstr - locate substring @needle in string @haystack
 *
 * @haystack: string to search for instances of @haystack
 * @needle: substring to search @haystack for
 *
 * Return: a pointer to the beginning of the located substring, otherwise NULL
 */
char *_strstr(char *haystack, char *needle)
{
	while (*haystack != '\0')
	{
		char *start = haystack;
		char *lookingforme = needle;

		while (*lookingforme == *haystack && *lookingforme != '\0'
		       && *haystack != '\0')
		{
			haystack++;
			lookingforme++;
		}
		if (*lookingforme == '\0')
			return (start);
		haystack = start + 1;
	}
	return ('\0');
}
