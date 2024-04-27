#include "sort.h"
#include <stdio.h>

/**
 * bubble_sort - Sorts an array of integers in ascending order.
 *
 * @array: Pointer to the array of integers.
 * @size: Number of elements in the array.
 *
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t i; /* Index for looping through the array */
	int temp; /* Temporary variable to hold a value during swapping */
	int sorted; /* Indicator for whether the array is sorted */

	if (array == NULL || size < 2)
	{
		/* No sorting needed for empty or single-element arrays */
		return;
	}

	sorted = 0; /* Assume the array is not sorted initially */
	while (!sorted)
	{
		sorted = 1; /* Assume the array is sorted until proven otherwise */
		for (i = 0; i < size - 1; i++)
		{
			/* Loop through the array */
			if (array[i] > array[i + 1])
			{
				/* If the elements are out of order, swap them */
				sorted = 0; /* The array isn't sorted yet */
				temp = array[i];/* Save the current value */
				array[i] = array[i + 1];/* Swap the elements */
				array[i + 1] = temp; /* Complete the swap */
				print_array(array, size); /* Optional: print current state */
			}
		}
	}
}

