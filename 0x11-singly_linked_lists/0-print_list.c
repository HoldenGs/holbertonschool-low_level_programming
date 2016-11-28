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
	const list_t *list;
	int i;

	list = h;
	i = 0;
	while (list != 0)
	{
		printf("[%d] %s\n", list->len, list->str);
		list = list->next;
		i++;
	}

	return (i);
}
