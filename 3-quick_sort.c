#include "sort.h"

/**
 * partition - employs the lomuto partition scheme to choose
 * a pivot and return the index of the pivot when sorted
 * @array: the array to be sorted
 * @size: size of the array
 * @start_index: the start index of the array to be sorted
 * @end_index: the end index of the array to be sorted
 *
 * Return: index of a sorted pivot element
 */
size_t partition(int *array, size_t size, size_t start_index, size_t end_index)
{
	int	   pivot	   = array[end_index]; /* the pivot element */
	size_t pivot_index = start_index; /* final index of pivot el when sorted */
	size_t curr_index;				  /* index for traversing the array */
	int	   temp; /* temporary placeholder used in swapping*/

	for (curr_index = start_index; curr_index < end_index; curr_index++)
	{
		if (array[curr_index] < pivot)
		{
			if (curr_index != pivot_index) /* Print array if swaps happen */
			{
				/* swap the elements */
				temp			   = array[curr_index];
				array[curr_index]  = array[pivot_index];
				array[pivot_index] = temp;

				/* print array after swap */
				print_array(array, size);
			}
			/* increment the pivot index */
			pivot_index++;
		}
	}

	if (pivot_index != end_index)
	{
		/* swap pivot with element at pivot_index to sort the pivot */
		temp			   = array[pivot_index];
		array[pivot_index] = pivot;
		array[end_index]   = temp;

		/* print array after pivot swap */
		print_array(array, size);
	}

	return (pivot_index);
}

/**
 * sort - sorts an array recursively using the quick sort
 * algorithm and the lomuto partioning scheme
 * @array: the array to be sorted
 * @size: size of the array
 * @start_index: the start index of the array to be sorted
 * @end_index: the end index of the array to be sorted
 */
void sort(int *array, size_t size, size_t start_index, size_t end_index)
{
	size_t pivot_index;

	/* base case */
	if (start_index == end_index) /* subarray sorted if only one element */
		return;

	/* get the index of the pivot element */
	pivot_index = partition(array, size, start_index, end_index);

	/* recursive sort the array elements to the left of the pivot */
	if (pivot_index > start_index) /* prevents out of bounds index */
		sort(array, size, start_index, pivot_index - 1);

	/* recursive sort the array elements to the right of the pivot */
	if (pivot_index < end_index) /* prevents out of bounds index */
		sort(array, size, pivot_index + 1, end_index);
}

/**
 * quick_sort - sorts an array of ints using the quick sort alorithm
 * @array: the array to be sorted
 * @size: the size of the array
 */
void quick_sort(int *array, size_t size)
{
	size_t start_index = 0;
	size_t end_index   = size - 1;

	if (array == NULL || size < 2) /* empty or single element array */
		return;

	sort(array, size, start_index, end_index);
}
