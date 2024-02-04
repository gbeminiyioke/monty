#include "monty.h"

/**
 * free_stack - this function frees a doubly linked
 * list
 * @head: this is the head of the stack
 * Return: nothing.
 */

void free_stack(stack_t *head)
{
	stack_t *loc;

	loc = head;
	while (head)
	{
		loc = head->next;
		free(head);
		head = loc;
	}
}
