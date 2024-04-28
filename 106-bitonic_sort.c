#include "sort.h"
#include <stdio.h>

/**
 * elements_swap - Swaps two elements in an array based on
 * the specified order.
 * @array: Pointer to the array.
 * @index1: Index of the first element.
 * @index2: Index of the second element.
 * @isAscend: 1 for ascending order, 0 for descending order.
 */
void elements_swap(int array[], int index1, int index2, int isAscend)
{
	int temp;

	if (isAscend == (array[index1] > array[index2]))
	{
		temp = array[index1];
		array[index1] = array[index2];
		array[index2] = temp;
	}
}

/**
 * merge_sequences - Recursively sorts bitonic sequences.
 * @array: Pointer to the array.
 * @start: Starting index.
 * @elCout: Number of elements.
 * @isAscend: 1 for ascending order, 0 for descending order.
 */
void merge_sequences(int array[], int start, int elCout, int isAscend)
{
	int mid_point, index;

	if (elCout > 1)
	{
		mid_point = elCout / 2;

		/* Swap elements to create the bitonic sequence */
		for (index = start; index < start + mid_point; index++)
		{
			elements_swap(array, index, index + mid_point, isAscend);
		}

		/* Recursively merge the left and right sequences */
		merge_sequences(array, start, mid_point, isAscend);
		merge_sequences(array, start + mid_point, mid_point, isAscend);
	}
}

/**
 * bitoSort - Recursively sorts an array using bitonic sort.
 * @array: Pointer to the array.
 * @start: Starting index.
 * @elCout: Number of elements.
 * @isAscend: 1 for ascending order, 0 for descending order.
 * @array_size: Total size of the array.
 */
void bitoSort(int array[], int start, int elCout, int isAscend, int array_size)
{
	int mid_point;

	if (elCout > 1)
	{
		if (isAscend)
		{
			printf("Merging [%i/%i] (UP):\n", elCout, array_size);
		}
		else
		{
			printf("Merging [%i/%i] (DOWN):\n", elCout, array_size);
		}
		print_array(&array[start], elCout);

		mid_point = elCout / 2;

		/* Recursively sort the left and right halves */
		bitoSort(array, start, mid_point, 1, array_size);
		bitoSort(array, start + mid_point, mid_point, 0, array_size);

		/* Merge the sorted sequences */
		merge_sequences(array, start, elCout, isAscend);

		/* Display the result */
		if (isAscend)
		{
			printf("Result [%i/%i] (UP):\n", elCout, array_size);
		}
		else
		{
			printf("Result [%i/%i] (DOWN):\n", elCout, array_size);
		}
		print_array(&array[start], elCout);
	}
}

/**
 * bitonic_sort - Prepares the array for bitonic sort and initiates sorting.
 * @array: Pointer to the array.
 * @array_size: Total size of the array.
 */
void bitonic_sort(int *array, size_t array_size)
{
	int isAscend = 1; /* 1 for ascending sort */

	if (array == NULL || array_size < 2)
	{
		/* If the array is null or too small, no need to sort */
		return;
	}

	/* Start the recursive bitonic sort */
	bitoSort(array, 0, array_size, isAscend, array_size);
}

