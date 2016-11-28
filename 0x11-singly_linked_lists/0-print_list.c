#include "lists.h"
#include <stdio.h>

/**
 * print_list - print all elements of a linked list
 * @h: linked list
 *
 * Return: The number of nodes in the list
 */
size_t print_list(const list_t *h)
{
	size_t *i;
	const list_t list;
	int j;

	list = h;
	j = 0;
	printf("[%d] %s\n", i->len, i->str);
	if (h->next == NULL)
		return (j + 1);
	i = i->next;
	j++;

	return (j + 1);
}
