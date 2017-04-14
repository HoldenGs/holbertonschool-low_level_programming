#include "search_algos.h"

/**
 * binary_search - search a sorted array by dividing by 2's
 *
 * @array: array to search
 * @size: size of array
 * @value: value we're looking for
 *
 * Return: index where @value was found; -1 if not found
 */
int binary_search(int *array, size_t size, int value)
{
	size_t left_idx, right_idx, mid_idx, print_i;

	if (array == NULL)
		return (-1);
	left_idx = 0;
	right_idx = size - 1;
	while (left_idx <= right_idx)
	{
		printf("Searching in array: ");
		for (print_i = left_idx; print_i <= right_idx; print_i++)
		{
			if (print_i == right_idx)
				printf("%d\n", array[print_i]);
			else
				printf("%d, ", array[print_i]);
		}
		mid_idx = (left_idx + right_idx) / 2;
		if (array[mid_idx] > value)
			right_idx = mid_idx;
		else if (array[mid_idx] < value)
			left_idx = mid_idx + 1;
		else
			return (mid_idx);
	}
	return (-1);
}
