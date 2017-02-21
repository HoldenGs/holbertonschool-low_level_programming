#include "../sort.h"


/**
 * selection_sort - sort an array with selection sort
 * @array: array of int
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index;
	int tmp;

	if (size < 2)
		return;

	for (i = 0; i < size - 1; ++i)
	{
		min_index = i;
		for (j = i; j < size ; ++j)
		{
			if (array[j] < array[min_index])
				min_index = j;
		}
		if (min_index != i)
		{
			tmp = array[i];
			array[i] = array[min_index];
			array[min_index] = tmp;
			print_array(array, size);
		}
	}
}
