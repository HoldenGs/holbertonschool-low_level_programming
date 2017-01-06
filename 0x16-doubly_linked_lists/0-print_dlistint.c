#include "lists.h"

/**
 * print_dlistint - prints a doubly linked list
 *
 * @h: list head
 *
 * Return: size of list
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t i;

	for (i = 0; h != NULL; i++)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
	return (i);
}
