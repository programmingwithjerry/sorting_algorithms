#include "sort.h"
#include <stdio.h>

/**
 * find_maximum - Utility function to find the maximum value in an array.
 * @array: Pointer to the array.
 * @size: Number of elements in the array.
 *
 * Return: The maximum value in the array.
 */
int find_maximum(int *array, int size)
{
	int max_value = array[0]; /* Initialize maximum with the first element */
	int index = 1; /* Loop index */

	/* Find the maximum value */
	while (index < size)
	{
		if (array[index] > max_value)
		{
			max_value = array[index];
		}
		index++;
	}

	return (max_value); /* Return the maximum value */
}

/**
 * count_sort - Function to do counting sort based on the given digit.
 * @array: Pointer to the array to be sorted.
 * @size: Number of elements in the array.
 * @exp: The digit to sort by (10^i).
 * @temp_array: Temporary array to hold sorted values.
 */
void count_sort(int *array, size_t size, int exp, int *temp_array)
{
	int count[10] = {0}; /* Array to count digit occurrences */
	int index = 0; /* Loop index */
	int digit;
	int position;

	/* Count the occurrences of each digit */
	while (index < (int)size)
	{
		digit = (array[index] / exp) % 10;
		count[digit]++;
		index++;
	}

	/* Convert the count to cumulative counts for positions */
	index = 1;
	while (index < 10)
	{
		count[index] += count[index - 1];
		index++;
	}

	/* Build the temporary array for sorted elements */
	index = size - 1;
	while (index >= 0)
	{
		digit = (array[index] / exp) % 10;
		position = count[digit] - 1;
		temp_array[position] = array[index];
		count[digit]--;
		index--;
	}

	/* Copy the sorted values from the temporary array to the original array */
	index = 0;
	while (index < (int)size)
	{
		array[index] = temp_array[index];
		index++;
	}
}

/**
 * radix_sort - Main function to sort an array of integers using Radix Sort.
 * @array: Pointer to the array to be sorted.
 * @size: Number of elements in the array.
 */
void radix_sort(int *array, size_t size)
{
	int max_value = 0; /* The maximum value in the array */
	int exponent = 1; /* Exponent to sort by digit */
	int *temp_array = NULL; /* Temporary array for sorting */

	if (array == NULL || size < 2)
	{
		/* Return if the array is null or has fewer than two elements */
		return;
	}

	max_value = find_maximum(array, size); /* Find the maximum value */
	temp_array = malloc(size * sizeof(int)); /* Allocate temporary array */

	if (temp_array == NULL)
	{
		/* If memory allocation fails, return */
		return;
	}

	/* Perform counting sort for each digit */
	while (max_value / exponent > 0)
	{
		count_sort(array, size, exponent, temp_array);
		print_array(array, size);
		exponent *= 10; /* Move to the next digit */
	}

	free(temp_array); /* Free the allocated memory for the temporary array */
}

