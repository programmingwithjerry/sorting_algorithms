#include "sort.h"

/**
 * swap - Swaps the positions of two elements in an array.
 * @array: The array containing the elements to swap.
 * @first_index: Index of the first element to swap.
 * @second_index: Index of the second element to swap.
 */
void swap(int *array, int first_index, int second_index)
{
	int temp; /* Temporary variable for swapping */

	temp = array[first_index]; /* Save the first element */
	/* Swap the second element into the first index */
	array[first_index] = array[second_index];
	/* Swap the saved element into the second index */
	array[second_index] = temp;
}

/**
 * shell_sort - Sorts an array of integers in ascending order using
 * the Shell sort algorithm with the Knuth sequence.
 * @array: Pointer to the array to sort.
 * @size: Size of the array.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1; /* Initial gap for the Shell sort */
	size_t i, j; /* Loop indices */

	if (array == NULL || size < 2)
	{
		/* Return if the array is null or has fewer than 2 elements */
		return;
	}

	/* Calculate the initial gap using the Knuth sequence */
	while (gap < size / 3)
	{
		gap = 3 * gap + 1;
	}

	/* Start sorting with the gap */
	for (; gap >= 1; gap /= 3)
	{
		/* Continue until the gap is less than 1 */
		for (i = gap; i < size; i++)
		{
			/* Loop over the array starting at the gap */
			for (j = i; j >= gap && array[j] < array[j - gap]; j -= gap)
			{
				/* Swap elements to maintain the sorted order with the current gap */
				swap(array, j, j - gap);
			}
		}
		/* Optional: Print the array after each gap sort */
		print_array(array, size);
	}
}

