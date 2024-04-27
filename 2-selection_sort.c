#include "sort.h"
#include <stdio.h>

/**
 * selection_sort - Sorts an array of integers in ascending
 * order using the selection sort algorithm.
 * @array: The array of integers to be sorted.
 * @size: The size of the array.
 *
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0; /* Current position in the outer loop */
	size_t j; /* Index for the inner loop */
	size_t min_index; /* Index of the minimum element found */
	int temp; /* Temporary variable for swapping */

	/* Continue until the last unsorted element */
	while (i < size - 1)
	{
		min_index = i; /* Assume the current position is the minimum */

		/* Initialize the inner loop index */
		j = i + 1;
		/* Loop through the unsorted part to find the minimum element */
		while (j < size)
		{
			if (array[j] < array[min_index])
			{
				min_index = j;
			}
			j++; /* Move to the next element */
		}
		/* Swap the current element with the minimum element found */
		if (min_index != i)
		{
			temp = array[i]; /* Save the current value */
			array[i] = array[min_index];
			array[min_index] = temp; /* Complete the swap */
			/* Optional: Print the array after each swap */
			print_array(array, size);
		}
		i++; /* Move to the next step in the outer loop */
	}
}

