#include "lists.h"

/**
 * listint_t - print all elements of the listint_t linked list
 * @h: linked list
 *
 * Return: the number of nodes
 */
size_t print_listint(const listint_t *h)
{
	int i;

	i = 0;
	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		i++;
	}
	return (i);
}
