#include "monty.h"

/**
 * m_queue - sets the format of the data to a
 * queue (FIFO).
 * @head: this is the head of tbe stack
 * @line_num: this is the line number
 * Return: nothing
 */

void m_queue(stack_t **head, unsigned int line_num)
{
	(void)head;
	(void)line_num;
	bus.lifi = 1;
}

/**
 * addqueue - this function adds a node to the tail
 * of the stack
 * @head: this is the head of the stack
 * @nwval: the new value to add
 * Return: nothing
 */

void addqueue(stack_t **head, int nwval)
{
	stack_t *loc;
	stack_t *n_node;

	loc = *head;
	n_node = malloc(sizeof(stack_t));
	if (n_node == NULL)
	{
		printf("Error\n");
	}
	n_node->n = nwval;
	n_node->next = NULL;
	if (loc)
	{
		while (loc->next)
			loc = loc->next;
	}
	if (!loc)
	{
		*head = n_node;
		n_node->prev = NULL;
	}
	else
	{
		loc->next = n_node;
		n_node->prev = loc;
	}
}
