#include "sort.h"

/**
 * bubble_sort - sorts an array using the algorithm
 * @array: the array to sort
 * @size: the size of the array
 */
void bubble_sort(int *array, size_t size)
{
	int temp, index, pass;
	bool swapped = true;

	if (array == NULL || size < 2)
		return;

	for (pass = size - 1; pass > 0 && swapped; pass--)
	{
		swapped = false;

		for (index = 0; index <= pass - 1; index++)
		{
			if (array[index] > array[index + 1])
			{
				/* swap elements and update swapped */
				temp = array[index];
				array[index] = array[index + 1];
				array[index + 1] = temp;

				print_array(array, size);
				swapped = true;
			}
		}
	}
}
