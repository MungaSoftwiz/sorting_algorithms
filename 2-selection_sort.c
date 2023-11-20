#include "sort.h"

/**
 * selection_sort - sorts an array in ascending order
 *                  using the selection sort algorithm
 * @array: the array to be sorted
 * @size: the size of tha array
 */
void selection_sort(int *array, size_t size)
{
	size_t current, next_idx, min;
	int temp;

	if (array == NULL || size < 2)
		return;

	for (current = 0; current < size; current++)
	{
		min = current;
		for (next_idx = current + 1; next_idx < size; next_idx++)
		{
			if (array[next_idx] < array[min])
				min = next_idx;
		}

		if (min != current)
		{
			temp = array[min];
			array[min] = array[current];
			array[current] = temp;

			print_array(array, size);
		}

	}
}
