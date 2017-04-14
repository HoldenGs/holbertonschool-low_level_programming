#include "search_algos.h"

/**
 * linear_search - search an a array in linear time complexity
 *
 * @array: array to search
 * @size: size of array
 * @value: value we're looking for
 *
 * Return: index where value was first located; -1 if not found
 */
int linear_search(int *array, size_t size, int value)
{
	size_t i;

	if (array == NULL)
		return (-1);
	for (i = 0; i < size; i++)
	{
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);
		if (array[i] == value)
		{
			return (i);
			printf("Found %d at index: %lu\n", value, i);
		}
	}
	return (-1);
}
