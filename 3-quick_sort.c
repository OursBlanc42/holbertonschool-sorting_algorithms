#include <stddef.h>
#include "sort.h"


/**
* recursive_quicksort - Recursively sorts array of integer
* by swap value arount a pivot (quick sort)
* @array: array to sort witch quick sort algorithm
* @bot: low index of the partition
* @top: high index of the partiion
* @size: size of the array
* Return: nothing
*/
void recursive_quicksort(int *array, int bot, int top, size_t size)
{
	/* declare and define value */
	int value_pivot = array[top];
	int top_marker = bot;
	int bot_marker = top_marker - 1;
	int stock;

	/* loop in the array */
	while (top_marker < (int)size)
	{
		/* If the current element is less than the pivot, swap it */
		if (array[top_marker] < value_pivot)
		{
			bot_marker++; /* update marker forward */

			/* swap element */
			stock = array[top_marker];
			array[top_marker] = array[bot_marker];
			array[bot_marker] = stock;
		}
		/* update top marker forward */
		top_marker++;
	}

	/* Once is done, update pivot position after the smallest element swapped */
	bot_marker++;
	stock = array[bot_marker];
	array[bot_marker] = array[size - 1];
	array[size - 1] = stock;

	/* print after each swap */
	print_array(array, size);

	/* recursive call (left subarray then right sub array)*/
	recursive_quicksort(array, bot, bot_marker - 1, size);
	recursive_quicksort(array, bot_marker + 1, top, size);
}



/**
* quick_sort - Entry point :
* by using algorithm quick sort
* @array: array to sort witch quick sort algorithm
* @size: size of the array
* Return: nothing
*/
void quick_sort(int *array, size_t size)
{
	/* Check special case*/
	if (array == NULL)
		return;

	/* if there is one value in the array, nothing to sort*/
	if (size < 2)
		return;

	/* call quick_algo for the first time  */
	/*quickalgo(array, begin, end, size )*/
		recursive_quicksort(array, 0, size - 1, size);
}


