#include "sort.h"
#include <stdio.h>

/**
 * calloc_custom - Allocates memory for an array of
 * elements and initializes them to zero.
 * @num_elements: Number of elements to allocate.
 * @element_size: Size of each element in bytes.
 *
 * Return: Pointer to the allocated memory or NULL on failure.
 */
void *calloc_custom(unsigned int num_elements, unsigned int element_size)
{
	unsigned int index = 0; /* Loop index for initialization */
	char *memory_block; /* Pointer to the allocated memory */

	if (num_elements == 0 || element_size == 0)
	{
		/* Return NULL if the number of elements or size is zero */
		return (NULL);
	}

	memory_block = malloc(num_elements * element_size); /* Allocate memory */
	if (memory_block == NULL)
	{
		/* Return NULL if allocation fails */
		return (NULL);
	}

	/* Initialize the allocated memory to zero */
	for (index = 0; index < (num_elements * element_size); index++)
	{
		memory_block[index] = 0; /* Set each byte to zero */
	}

	return (memory_block); /* Return the allocated and initialized memory */
}

/**
 * counting_sort - Sorts an array of integers in ascending
 * order using the counting sort algorithm.
 * @array: Pointer to the array to sort.
 * @size: Size of the array.
 */
void counting_sort(int *array, size_t size)
{
	int *count_array = NULL; /* Array to store counts of each unique element */
	int *sorted_array = NULL; /* Temporary array for sorted elements */
	int max_value = 0; /* The maximum value in the input array */
	size_t i; /* Loop index for traversal */
	int index; /* Loop index for cumulative count (signed type) */

	if (array == NULL || size < 2)
		return;
	/* Find the maximum value in the array */
	for (i = 0; i < size; i++)
	{
		if (array[i] > max_value)
			max_value = array[i];
	}
	/* Allocate memory for the count and temporary arrays */
	count_array = calloc_custom(max_value + 1, sizeof(int));
	sorted_array = calloc_custom(size, sizeof(int));

	/* Count the occurrences of each element in the original array */
	for (i = 0; i < size; i++)
		count_array[array[i]]++; /* Increment the count for each element */
	/* Calculate the cumulative counts for sorting */
	for (index = 1; index <= max_value; index++)
		count_array[index] += count_array[index - 1]; /* Accumulate counts */

	print_array(count_array, max_value + 1); /* Optional: Print the count array */
	/* Sort the array using the cumulative counts */
	for (i = 0; i < size; i++)
	{
		sorted_array[count_array[array[i]] - 1] = array[i];
		count_array[array[i]]--; /* Decrement the count */
	}
	/* Copy the sorted elements back to the original array */
	for (i = 0; i < size; i++)
		array[i] = sorted_array[i]; /* Replace old array with sorted elements */

	/* Free the allocated memory for the count and temporary arrays */
	free(sorted_array);
	free(count_array);
}

