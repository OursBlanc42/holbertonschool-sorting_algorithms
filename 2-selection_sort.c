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
	int play_again = 0;

	/* For each value in the array...*/
	for (index = 0; index < (int)size; index++)
	{
		play_again = 0; 		/* reset checker */
		index_mini = index;		/* suppose first digit at minimum */
		mini =  array[index];	/* Set mini to first element */

		/* Search minimum element in the list */
		for (cursor = (index + 1) ; cursor < (int)size; cursor++)
		{
			if (array[cursor] < mini)
			{
				mini = array[cursor];
				index_mini = cursor;
			}
		}

		/* Swap value and print result */
		buffer = array[index];
		array[index] = array[index_mini];
		array[index_mini] = buffer;
		print_array((const int *)array, size);

		/* check if the list is in right order to avoid useless traverse */
		for (cursor = (index + 1) ; cursor < (int)size; cursor++)
		{
			if (array[cursor - 1] > array [cursor])
			{
				play_again = 1;
			}
		}

		/* if is the right order : stop it, otherwise play again*/
		if (play_again == 0)
			return ;
	}

}
