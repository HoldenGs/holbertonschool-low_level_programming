#include "lists.h"

/**
 * list_len - find the element of a linked list
 * @h: linked list
 *
 * Return: number of elements in linked list @h
 */
size_t list_len(const list_t *h)
{
	int i;

	i = 0;
	while (h != 0)
	{
		h = h->next;
		i++;
	}
	return (i);
}
