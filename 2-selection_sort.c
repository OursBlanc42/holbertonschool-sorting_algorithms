#include <stddef.h>
#include "sort.h"
#include <stdio.h>

/**
* selection_sort - sorts an array of integers in ascending order using the
* selection_sort algorithm
* @array: input array of int
* @size: size of the array
* Return: Always 0
*/

void selection_sort(int *array, size_t size)
{
	/* declare and initialize variable */
	int mini = 0;
	int index = 0;
	int index_mini = 0;
	int cursor = 0;
	int buffer = 0;
	int swapped = 0;

	/* For each value in the array...*/
	for (cursor = 0; cursor < (int)size; cursor++)
	{
		swapped = 0;	/* reset swapped state */
		mini = array[cursor];

		/* traverse the array and find the minimum value */
		for (index = cursor; index < (int)size; index++)
		{
			/* check if we find a smaller value*/
			if (array[index] < mini)
			{
				mini = array[index];
				index_mini = index;
				swapped = 1;
			}
		}

		/* swap value */
		buffer = array[index_mini];
		array[index_mini] = array[cursor];
		array[cursor] = buffer;

		print_array((const int *)array, size);

		/* if zero swap that mean everything is ordered */
		if (swapped == 0)
			return;
	}

}
