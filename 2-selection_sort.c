#include "sort.h"

/**
 * selection_sort - sorts an array of ints using the selection sort alorithm
 * @array: the array to be sorted
 * @size: the size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, minIndex;
	int	   temp;

	if (array == NULL || size == 0) /* null or empty array */
		return;

	for (i = 0; i < size; i++)
	{
		minIndex = i;

		for (j = i + 1; j < size; j++)
		{
			/* find the index of the smallest number */
			if (array[j] < array[minIndex])
			{
				minIndex = j;
			}
		}

		if (minIndex != i)
		{
			/* using the found index, swap the min number with selected */
			temp			= array[minIndex];
			array[minIndex] = array[i];
			array[i]		= temp;

			/* print the current state of the array */
			print_array(array, size);
		}
	}
}
