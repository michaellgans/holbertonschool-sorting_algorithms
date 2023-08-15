#include "sort.h"

/**
 * bubble_sort - sorts bubbles
 * @array: pointer to array
 * @size: size of array
 */

void bubble_sort(int *array, size_t size)
{
	/* Declare and Initialize Variables */
	int swapped = 0;
	size_t x, y;

	if (array == NULL || size <= 1)
		return;

	for (x = 0; x < size - 1; x++)
	{
		for (y = 0; y < size - x - 1; y++)
		{
			if (array[y] > array[y + 1])
			{
				int temp = array[y];

				array[y] = array[y + 1];
				array[y + 1] = temp;

				print_array(array, size);
				swapped = 1;
			}
		}
		if (swapped == 0)
			break;
	}
}
