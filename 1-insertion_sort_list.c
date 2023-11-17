#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending order using Insertion sort
 * @list: Pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	listint_t *current, *temp, *prev;

	current = (*list)->next;

	while (current != NULL)
	{
		temp = current;
		prev = current->prev;

		while (prev != NULL && prev->n > temp->n)
		{
			if (temp->next != NULL)
				temp->next->prev = prev;

			prev->next = temp->next;
			temp->next = prev;
			temp->prev = prev->prev;

			if (prev->prev != NULL)
				prev->prev->next = temp;
			else
				*list = temp;

			prev->prev = temp;
			prev = temp->prev;

			print_list(*list);
		}

		current = current->next;
	}
}
