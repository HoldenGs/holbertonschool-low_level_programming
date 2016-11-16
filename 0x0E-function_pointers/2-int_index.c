/**
 * int_index - search for an integer in an array using @cmp
 * @array: array
 * @size: size of array
 * @cmp: function used to look for an integer
 *
 * Return: Index of @array where match is found; -1 if failure or none is found
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (size < 1 || array == NULL || cmp == NULL)
		return (-1);

	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]))
			return (i);
	}
	return (-1);
}
