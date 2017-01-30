#include "monty.h"

/**
 * smart_alloc - allocate memory with error handling
 *
 * @size: size of memory to allocate
 *
 * Return: pointer to memory if success; EXIT_FAILURE if failure
 */
void *smart_alloc(size_t size)
{
	void *ptr;

	ptr = malloc(size);
	if (ptr == NULL)
	{
		printf("Error: Malloc failed\n");
		exit(EXIT_FAILURE);
	}
	return (ptr);
}

/**
 * free_list - free a doubly linked list from memory
 *
 * @head: list head
 *
 * Return: void
 */
void free_list(stack_t *head)
{
	stack_t *walker, *tmp;

	if (head != NULL)
	{
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
}
