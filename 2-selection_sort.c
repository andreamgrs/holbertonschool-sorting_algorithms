#include "sort.h"
#include <stdlib.h>
/**
 * selection_sort - function that sorts an array of integers in
 * ascending order using the selection sort algorithm.
 *
 * @array: is a pointer to the first element in the array.
 * @size: number of elements in the array.
 *
 * Return: nothing.
 *
 */
void selection_sort(int *array, size_t size)
{
	size_t array_size;
	size_t min_num;
	size_t cont = 0;
	int tmp;
	
	array_size = 0;
	while (array_size < size)
	{
		min_num = array_size;

		cont = min_num + 1;
		while (cont < size)
		{
			if(array[cont] < array[min_num])
			{
				min_num = cont;
			}
			cont = cont + 1;
		}

		if (min_num != array_size)
		{

			tmp = array[array_size];
			array[array_size] = array[min_num];
			array[min_num] = tmp;
			print_array(array, size);
		}
		array_size = array_size + 1;
	}
}
