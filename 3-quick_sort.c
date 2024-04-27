/**
 * swap_items - Swaps two elements in an array.
 * @array: Pointer to the array to modify.
 * @left_index: Index of the left element to swap.
 * @right_index: Index of the right element to swap.
 */
void swap_items(int *array, size_t left_index, size_t right_index)
{
	/* Temporary variable to hold one of the elements during the swap */
	int temp;

	if (array != NULL)
	{ /* Check that the array is not null */
		temp = array[left_index]; /* Save the left element */
		/* Swap the right element into the left position */
		array[left_index] = array[right_index];
		/* Put the saved element into the right position */
		array[right_index] = temp;
	}
}

/**
 * quick_sort_range_lomuto - Sorts a sub-array using the quick sort algorithm
 * with Lomuto's partition scheme.
 * @array: The array containing the sub-array.
 * @low: Starting position of the sub-array.
 * @high: Ending position of the sub-array.
 * @size: Total length of the array.
 *
 * Return: void
 */
void quick_sort_range_lomuto(int *array, size_t low, size_t high, size_t size)
{
	size_t i, j; /* Indices for partitioning and loop control */
	int pivot; /* The pivot element */

	if (array == NULL || low >= high)
	{
		/* If the array is null or the range is invalid, return */
		return;
	}
	pivot = array[high]; /* Set the pivot as the last element */
	i = low; /* Index for smaller elements during partitioning */
	/* Loop through the sub-array, excluding the pivot */
	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			if (i != j)
			{
				swap_items(array, i, j); /* Swap smaller element with i */
				print_array(array, size); /* Optional: Print the array after each swap */
			}
			i++; /* Move to the next smaller position */
		}
	}
	/* Place the pivot in its correct position */
	if (i != high)
	{
		swap_items(array, i, high); /* Swap pivot into its correct position */
		/* Optional: Print the array after placing the pivot */
		print_array(array, size);
	}
	/* Recursively sort the left and right sub-arrays */
	if (i - low > 1)
	{
		quick_sort_range_lomuto(array, low, i - 1, size);
	}
	if (high - i > 1)
	{
		quick_sort_range_lomuto(array, i + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array using the quick sort algorithm
 * and Lomuto's partition scheme.
 * @array: Array to sort.
 * @size: Length of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array != NULL)
	{
		quick_sort_range_lomuto(array, 0, size - 1, size);
	}
}
