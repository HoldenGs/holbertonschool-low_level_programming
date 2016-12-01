#include "lists.h"

/**
 * sum_listint - return the sum of all data in a listint_t linked list
 * @head: linked list
 *
 * Return: sum of all data; 0 if list is empty
 */
int sum_listint(listint_t *head)
{
	int i;

	i = 0;
	while (head != NULL)
	{
		i += head->n;
		head = head->next;
	}
	return (i);
}
