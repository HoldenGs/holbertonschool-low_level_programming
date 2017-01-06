#include "lists.h"

/**
 * sum_dlistint - return the sum of integer data in a doubly linked list
 *
 * @head: list head
 *
 * Return: sum of list data
 */
int sum_dlistint(dlistint_t *head)
{
	int sum;

	sum = 0;
	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}
	return (sum);
}
