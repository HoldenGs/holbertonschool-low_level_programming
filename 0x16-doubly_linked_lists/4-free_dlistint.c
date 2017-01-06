#include "lists.h"

void free_dlistint(dlistint_t *head)
{
	dlistint_t *walker, *tmp;

	walker = head;
	while (walker->next != NULL)
		walker = walker->next;
	while (walker != NULL)
	{
		tmp = walker;
		walker = walker->prev;
		free(tmp);
	}
}
