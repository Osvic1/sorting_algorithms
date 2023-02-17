#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in
 * ascending order using the Insertion sort algorithm
 *
 * @list: pointer to the first node of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *tmp;

	if (list == NULL || (*list) == NULL || (*list)->next == NULL)
		return;

	curr = (*list)->next;

	while (curr != NULL)
	{
		tmp = curr->prev;

		while (tmp != NULL && tmp->n > curr->n)
		{
			tmp->next = curr->next;

			if (curr->next != NULL)
				curr->next->prev = tmp;

			curr->next = tmp;
			curr->prev = tmp->prev;
			tmp->prev = curr;

			if (curr->prev == NULL)
				*list = curr;
			else
				curr->prev->next = curr;

			print_list(*list);
			tmp = curr->prev;
		}

		curr = curr->next;
	}
}
