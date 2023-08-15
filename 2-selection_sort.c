#include "sort.h"
#include <stdio.h>

/**
 * selection_sort - Sorts Selections
 * @array: array to be sorted
 * @size: size of array
 */

void selection_sort(int *array, size_t size)
{
	int x, y, z, temp;
	
	if (array == NULL || size <= 1)
		return;

	for (x = 0; x < (int)size - 1; x++)
	{
		z = x;
		for (y = x + 1; y < (int)size; y++)
		{
			if (array[y] < array[z])
				z = y;
		}

		if (z != x)
		{
			temp = array[x];
			array[x] = array[z];
			array[z] = temp;

			print_array(array, size);
		}
	}
}

