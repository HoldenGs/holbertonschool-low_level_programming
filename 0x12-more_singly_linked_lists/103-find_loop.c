#include "lists.h"

/**
 * find_listint_loop - find a loop in a linked list
 * @head: linked list
 *
 * Return: pointer to start of list; NULL if no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow, *fast;

	slow = head;
	fast = head->next;
	while (fast && fast->next)
	{
		if (slow == fast)
			break;
		slow = slow->next;
		fast = fast->next->next;
	}
	if (slow == fast)
	{
		slow = head;
		while (slow != fast->next)
		{
			slow = slow->next;
			fast = fast->next;
		}
		return (fast->next);
	}
	return (NULL);
}
