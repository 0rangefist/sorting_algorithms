#include "sort.h"

/**
 * bubble_sort - sorts an array of ints using the bubble sort alorithm
 * @array: the array to be sorted
 * @size: the size of the array
 */
void bubble_sort(int *array, size_t size)
{
	unsigned int i, j, temp;

	if (array == NULL || size == 0) /* null or empty array */
		return;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - 1 - i; j++)
		{
			/* if current value is larger than next */
			if (array[j] > array[j + 1])
			{
				/* swap the values */
				temp		 = array[j];
				array[j]	 = array[j + 1];
				array[j + 1] = temp;

				/* print the array as it is currently */
				print_array(array, size);
			}
		}
	}
}
