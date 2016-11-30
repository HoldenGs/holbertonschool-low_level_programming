#include "lists.h"

/**
 * listint_len - return the number of elements in the listint_t linked list
 * @h: linked list
 *
 * Return: the number of elements in the linked list
 */
size_t listint_len(const listint_t *h)
{
	int i;

	i = 0;
	while (h != NULL)
	{
		h = h->next;
		i++;
	}
	return (i);
}
