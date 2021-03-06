#include "search_algos.h"
#include <math.h>

/**
 * jump_search - search for @value using jump search algorithm
 *
 * @array: array to search through
 * @size: size of array
 * @value: value we're looking for
 *
 * Return: index position of @value; -1 if not found
 */
int jump_search(int *array, size_t size, int value)
{
	size_t prev, next, root;

	if (array == NULL)
		return (-1);
	root = sqrt(size);
	prev = 0;
	next = root;
	while (array[next] < value && next < size)
	{
		printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);
		prev = next;
		next += root;
		if (next >= size)
		{
			next = size - 1;
			break;
		}
	}
	printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);
	printf("Value found between indexes [%lu]", prev);
	printf(" and [%lu]\n", prev + root);
	while (prev < next)
	{
		printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);
		if (array[prev] == value)
			return (prev);
		prev++;
	}
	printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);
	return (-1);
}
