#include <stddef.h>
#include "sort.h"
/**
* quick_sort - function that sorts an array of integers in ascending order
* @array: array to sort witch quick sort algorithm
* @size: size of the array
* Return: nothing
*/
void quick_sort(int *array, size_t size)
{
	size_t pivot, index, preceding;
	int stock;

	/* if there is one value in the array, nothing to sort*/
	if (size < 2)
		return;

	/* We place the pivot on the last element*/
	pivot = size - 1;
	preceding = 0;

	/* partitionning the array*/
	for (index = 0; index < pivot; index++)
	{
		/* If the current element is less than the pivot, swap it */
		if (array[index] < array[pivot])
		{
			stock = array[index];
			array[index] = array[preceding];
			array[preceding] = stock;

			preceding++;
			/* print after every swap*/
			print_array(array, size);
		}
	}

	stock = array[preceding];
	array[preceding] = array[pivot];
	array[pivot] = stock;
 /* print after placing the pivot*/
	print_array(array, size);
	/* sort the left part*/
	quick_sort(array, preceding);
	/* sort the right part*/
	quick_sort(array + preceding + 1, size - preceding - 1);
}
