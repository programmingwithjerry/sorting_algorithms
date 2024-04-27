#include "sort.h"

/**
 * swap_elements - Swaps two elements in an array.
 * @array: Pointer to the array to modify.
 * @left_index: Index of the left element to swap.
 * @right_index: Index of the right element to swap.
 */
void swap_elements(int *array, size_t left_index, size_t right_index)
{
	int temp; /* Temporary variable to store the element during the swap */

	if (array != NULL)
	{
		/* Check if the array is valid */
		temp = array[left_index]; /* Store the left element */
		array[left_index] = array[right_index];
		array[right_index] = temp; /* Complete the swap */
	}
}

/**
 * quick_sort_range_lomuto - Sorts a sub-array using the quick sort algorithm
 * with Lomuto's partition scheme.
 * @array: Pointer to the array containing the sub-array.
 * @start: Starting index of the sub-array.
 * @end: Ending index of the sub-array.
 * @size: Total length of the array.
 */
void quick_sort_range_lomuto(int *array, size_t start, size_t end, size_t size)
{
	size_t i, j; /* Indices for partitioning */
	int pivot; /* The pivot element for partitioning */

	if ((start >= end) || (array == NULL))
	{
		/* If the range is invalid or the array is null, return */
		return;
	}

	pivot = array[end]; /* Set the pivot as the last element */
	i = start; /* Initial partition index for smaller elements */
	/* Loop through the sub-array, excluding the pivot */
	for (j = start; j < end; j++)
	{
		if (array[j] <= pivot)
		{
			if (i != j)
			{
				swap_elements(array, i, j); /* Swap smaller elements to maintain order */
				print_array(array, size); /* Optional: Print the array after each swap */
			}
			i++; /* Move the partition index for the next smaller element */
		}
	}
	/* Swap the pivot into its correct position */
	if (i != end)
	{
		swap_elements(array, i, end); /* Swap the pivot to its correct place */
		print_array(array, size); /* Optional: Print the array after final swap */
	}
	/* Recursively sort the sub-arrays on either side of the pivot */
	if (i - start > 1)
	{
		quick_sort_range_lomuto(array, start, i - 1, size);
	}
	if (end - i > 1)
	{
		quick_sort_range_lomuto(array, i + 1, end, size);
	}
}

/**
 * quick_sort - Sorts an array using the quick sort algorithm
 * with Lomuto's partition scheme.
 * @array: Pointer to the array to sort.
 * @size: Total length of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array != NULL)
	{
		/* Start the quick sort process */
		quick_sort_range_lomuto(array, 0, size - 1, size);
	}
}

