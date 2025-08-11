#include "sort.h"
#include <stdlib.h>
/**
 * insertion_sort_list - function that sorts a doubly linked
 * list of integers in ascending order using the Insertion
 * sort algorithm.
 *
 * @list: double pointer to the head of a doubly linked list.
 *
 * Return: nothing.
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *insert_node, *before_node, *after_node, *next_node;
	if (*list == NULL || list == NULL || (*list)->next == NULL)
	{
		return;
	}	

	current = (*list)->next;

	while (current != NULL)
	{
		insert_node = current;
		next_node = current->next;
		while (insert_node->prev != NULL && insert_node->n < insert_node->prev->n)
		{
			before_node = insert_node->prev;
			after_node = insert_node->next;

			before_node->next = after_node;

			if (after_node != NULL)
			{
				after_node->prev = before_node;
			}

			insert_node->prev = before_node->prev;
			insert_node->next = before_node;
			if (before_node->prev != NULL)
			{
				before_node->prev->next = insert_node; 
			}
			else
			{
				*list = insert_node;
			}
			before_node->prev = insert_node;
			print_list(*list);
		}
		current = next_node;
	}
}
