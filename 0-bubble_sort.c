#include "sort.h"
#include <stdlib.h>
/**
 * bubble_sort - function that sorts an array of integers in
 * ascending order using the Bubble sort algorithm.
 *
 * @array: is a pointer to the first element in the array.
 * @size: number of elements in the array.
 *
 * Return: nothing.
 *
 */
void bubble_sort(int *array, size_t size)
{
	size_t array_size;
	size_t num;
	int tmp = 0;

	array_size = 0;
	while (array_size < size - 1)
	{
		num = 0;
		while (num < size - 1 - array_size)
		{
			if (array[num] > array[num + 1])
			{
				tmp = array[num];
				array[num] = array[num + 1];
				array[num + 1] = tmp;
				print_array(array, size);
			}
			num = num + 1;
		}
		array_size = array_size + 1;
	}
}
