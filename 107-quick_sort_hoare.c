#include "sort.h"

/**
 * my_swaps - Swaps the positions of two elements in an array.
 * @array: Pointer to the array.
 * @first_index: Index of the first element to swap.
 * @second_index: Index of the second element to swap.
 */
void my_swaps(int *array, ssize_t first_index, ssize_t second_index)
{
	int temp;

	temp = array[first_index];
	array[first_index] = array[second_index];
	array[second_index] = temp;
}

/**
 * hoare_partition - Implements Hoare's partitioning scheme for quicksort.
 * @array: Pointer to the array to partition.
 * @start: Index of the first element.
 * @end: Index of the last element.
 * @array_size: Total size of the array.
 *
 * Return: The index of the last sorted element.
 */
int hoare_partition(int *array, int start, int end, int array_size)
{
	int left = start - 1; /* Left pointer */
	int right = end + 1; /* Right pointer */
	int pivot = array[end]; /* Pivot element */

	while (1)
	{
		do {
			left++;
		} while (array[left] < pivot); /* Move left pointer to the right */

		do {
			right--;
		} while (array[right] > pivot); /* Move right pointer to the left */

		if (left >= right)
		{
			return (left); /* Return the partition point */
		}

		my_swaps(array, left, right); /* Swap the elements */
		print_array(array, array_size); /* Print the array after swapping */
	}
}

/**
 * qs_recursive - Implements the recursive quicksort algorithm.
 * @array: Pointer to the array to sort.
 * @start: Index of the first element.
 * @end: Index of the last element.
 * @array_size: Total size of the array.
 */
void qs_recursive(int *array, ssize_t start, ssize_t end, int array_size)
{
	ssize_t partition_point;

	if (start < end)
	{
		/* Partition the array */
		partition_point = hoare_partition(array, start, end, array_size);
		/* Sort the left side */
		qs_recursive(array, start, partition_point - 1, array_size);
		/* Sort the right side */
		qs_recursive(array, partition_point, end, array_size);
	}
}

/**
 * quick_sort_hoare - Prepares the array for quicksort using
 * Hoare's partitioning scheme.
 * @array: Pointer to the array to sort.
 * @array_size: Total size of the array.
 */
void quick_sort_hoare(int *array, size_t array_size)
{
	if (!array || array_size < 2)
	{
		/**
		* No sorting needed for empty arrays or those
		* with fewer than two elements
		*/
		return;
	}
	/* Start the quicksort */
	qs_recursive(array, 0, array_size - 1, array_size);
}

