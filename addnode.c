#include "monty.h"

/**
 * addnode - this function adds a node to tbe head
 * of the stack
 * @head: this is the head of the stack
 * @n: the value to add
 * Return: nothing
 */

void addnode(stack_t **head, int n)
{
	stack_t *n_node;
	stack_t *loc;

	loc = *head;
	n_mode = malloc(sizeof(stack_t));
	if (n_node == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	if (loc)
		loc->prev = n_node;
	n_node->n = n;
	n_node->next = *head;
	n_node->prev = NULL;
	*head = n_node;
}
