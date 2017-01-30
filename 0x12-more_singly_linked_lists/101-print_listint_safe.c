#include "lists.h"

/**
 * print_listint_safe - print a linked list
 * @head: linked list
 *
 * Return: the number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	listint_t *slow, *fast, *normal;

	slow = fast = head;
	while (fast && fast->next)
	{
		if (slow == fast)
			break;
	}
}
