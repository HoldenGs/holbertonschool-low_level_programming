#include "heap.h"

/**
 * heap_create - create a heap data structure
 *
 * @data_cmp: difference of two node values
 *
 * Return: a new heap data structure
 */
heap_t *heap_create(int (*data_cmp)(void *, void *))
{
	heap_t *heap;

	if (!data_cmp)
		return (NULL);
	heap = malloc(sizeof(heap_t));
	if (!heap)
		return (NULL);
	heap->size = 0;
	heap->root = NULL;
	heap->data_cmp = data_cmp;
	return (heap);
}
