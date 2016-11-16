#include <stdlib.h>

/**
 * array_iterator - execute @action function on each element of @array
 * @array: array
 * @size: size of array
 * @action: function
 *
 * Return: void
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i;

	for (i = 0; i < size; i++)
		action(array[i]);
}
