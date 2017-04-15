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

	root = sqrt(size);
	prev = 0;
	next = root;
	while (array[next] < value && next < size)
	{
		printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);
		printf("Value checked array[%lu] = [%d]\n", next, array[next]);
		prev = next;
		next += root;
	}
	printf("Value found between indexes [%lu]", prev);
	printf(" and [%lu]\n", next);
	while (array[prev] <= value && prev < size)
	{
		if (prev >= size)
			return (-1);
		printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);
		if (array[prev] == value)
			return (prev);
		prev++;
	}
	return (-1);
}
