#include "sort.h"
#include <stdio.h>

/**
 * allocate_and_init - Allocates memory for
 * an array and initializes it to zero.
 * @element_count: Number of elements to allocate.
 * @element_size: Size of each element in bytes.
 *
 * Return: Pointer to the allocated memory, or NULL if allocation fails.
 */
void *allocate_and_init(unsigned int element_count, unsigned int element_size)
{
	unsigned int index = 0; /* Loop index for initialization */
	char *memory_block; /* Pointer to the allocated memory */

	if (element_count == 0 || element_size == 0)
	{
		/* Return NULL if there's nothing to allocate */
		return (NULL);
	}

	memory_block = malloc(element_count * element_size); /* Allocate memory */
	if (memory_block == NULL)
	{
		/* Return NULL if allocation fails */
		return (NULL);
	}

	/* Initialize the allocated memory to zero */
	for (index = 0; index < (element_count * element_size); index++)
	{
		memory_block[index] = 0; /* Set to zero */
	}

	return (memory_block); /* Return the initialized memory */
}

/**
 * merge_arrays - Merges two halves of an array into a temporary array.
 * @array: The original array.
 * @temp_array: Temporary array used for merging.
 * @start: Start index of the first half.
 * @middle: Middle index dividing the two halves.
 * @end: End index of the second half.
 */
void merge_arrays(int *array, int *temp_array, int start, int middle, int end)
{
	int left_size = middle - start + 1; /* Size of the left half */
	int right_size = end - middle; /* Size of the right half */
	int *left_half = &temp_array[0]; /* Start of the left half */
	int *right_half = &temp_array[left_size]; /* Start of the right half */
	int left_index = 0, right_index = 0, main_index = start;

	for (; left_index < left_size; left_index++)
		left_half[left_index] = array[start + left_index];
	for (; right_index < right_size; right_index++)
		right_half[right_index] = array[middle + 1 + right_index];
	left_index = 0;
	right_index = 0;
	while (left_index < left_size && right_index < right_size)
	{
		if (left_half[left_index] <= right_half[right_index])
		{
			array[main_index] = left_half[left_index];
			left_index++;
		}
		else
		{
			array[main_index] = right_half[right_index];
			right_index++;
		}
		main_index++;
	}
	while (left_index < left_size)
		array[main_index++] = left_half[left_index++];
	while (right_index < right_size)
		array[main_index++] = right_half[right_index++];
	printf("Merging...\n");
	printf("[Left]: ");
	print_array(left_half, left_size); /* Display the left half */
	printf("[Right]: ");
	print_array(right_half, right_size); /* Display the right half */
	printf("[Result]: ");
	print_array(&array[start], left_size + right_size);
}

/**
 * recursive_merge_sort - Recursively sorts an array of
 * integers using the Merge sort algorithm.
 * @array: The original array to sort.
 * @temp_array: Temporary array used during merge.
 * @start: Start index of the array to sort.
 * @end: End index of the array to sort.
 *
 * Return: void
 */
void recursive_merge_sort(int *array, int *temp_array, int start, int end)
{
	int middle; /* Middle index for dividing the array */

	middle = (start + end) / 2; /* Calculate the middle */
	if ((start + end) % 2 == 0)
	{
		middle--; /* Adjust middle if needed */
	}

	if (middle >= start)
	{
		recursive_merge_sort(array, temp_array, start, middle);
		/* Sort the right half */
		recursive_merge_sort(array, temp_array, middle + 1, end);
		/* Merge the two halves */
		merge_arrays(array, temp_array, start, middle, end);
	}
}

/**
 * merge_sort - Sorts an array of integers in ascending order
 * using the Merge sort algorithm.
 * @array: The array to sort.
 * @size: Size of the array.
 *
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	int *temp_array; /* Temporary array for merging */

	if (array == NULL || size < 2)
	{
		/* Return if the array is null or has fewer than two elements */
		return;
	}
	/* Allocate temp array */
	temp_array = allocate_and_init(size, sizeof(int));
	if (temp_array == NULL)
	{
		/* Return if allocation fails */
		return;
	}

	recursive_merge_sort(array, temp_array, 0, size - 1);

	free(temp_array); /* Free the allocated temporary array */
}

