#include "sort.h"
#include <stdlib.h>

/**
 * swap - function that swaps the values.
 *
 * @first: pointer to the first int of the array.
 * @last: pointer to the last int of the array.
 *
 * Return: nothing.
 *
 */
void swap(int *first, int *last)
{
	int tmp = *first;
	*first = *last;
	*last = tmp;

}

/**
 * partition - performs Lomuto partitioning on the subarray.
 *
 * @array: is a pointer to the first element in the array.
 * @size: number of elements in the array.
 * @min: starting index of the subarray.
 * @max: ending index of the subarray.
 *
 * Return: index where the pivot ends up.
 *
 */
int partition(int *array, size_t size, int min, int max)
{
	int pivot_value, cont, value_to_swap;

	pivot_value = array[max];
	value_to_swap = min;
	cont = min;
	while (cont < max)
	{
		if (array[cont] <= pivot_value)
		{
			if (value_to_swap != cont)
			{
				swap(&array[value_to_swap], &array[cont]);
				print_array(array, size);
			}
			value_to_swap++;
		}
		cont = cont + 1;
	}
	if (value_to_swap != max)
	{
		swap(&array[value_to_swap], &array[max]);
		print_array(array, size);
	}
	return (value_to_swap);

}
/**
 * quick_sort_recursion - recursively sorts an array quicksort.
 *
 * @array: is a pointer to the first element in the array.
 * @size: number of elements in the array.
 * @min: starting index of the subarray.
 * @max: ending index of the subarray.
 * 
 * Return: nothing.
 *
 */
void quick_sort_recursion(int *array, size_t size, int min, int max)
{
	int pivot;

	if (min < max)
	{
		pivot = partition(array, size, min, max);
		quick_sort_recursion(array, size, min, pivot - 1);
		quick_sort_recursion(array, size, pivot + 1, max);
	}
}
/**
 * quick_sort - function that sorts an array of integers in
 * ascending order using the quick sort algorithm.
 *
 * @array: is a pointer to the first element in the array.
 * @size: number of elements in the array.
 *
 * Return: nothing.
 *
 */
void quick_sort(int *array, size_t size)
{
	quick_sort_recursion(array, size, 0, size - 1);
}
