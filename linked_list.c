#include "monty.h"

/**
 * queue_node - this function adds a node to a
 * stack_t stack in queue_node
 * @stack: this is the head of the stack
 * @n: number of the node
 * Return: newly created node, NULL if memory
 * allocation fails, the function will
 */

stack_t *queue_node(stack_t **stack, const int n)
{
	stack_t *loc = *stack;
	stack_t *nxt = malloc(sizeof(stack_t));

	if (!nxt)
	{
		free(nxt);
		return (NULL);
	}
	nxt->n = n;
	if (!*stack)
	{
		nxt->next = NULL;
		nxt->prev = NULL;
		*stack = nxt;
		return (nxt);
	}
	while (loc)
	{
		if (!loc->next)
		{
			nxt->next = NULL;
			nxt->prev = loc;
			loc->next = nxt;
			break;
		}
		loc = loc->next;
	}
	return (nxt);
}

/**
 * add_node - this function adds a node to the start
 * of a stack_t stack
 * @stack: this is the head of the stack
 * @n: this is the number for the new node
 * Return: newly created node, NULL if creation fails
 */

stack_t *add_node(stack_t **stack, const int n)
{
	stack_t *nxt = malloc(sizeof(stack_t));

	if (!nxt)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(nxt);
		return (NULL);
	}
	nxt->n = n;
	nxt->next = *stack;
	nxt->prev = NULL;
	if (*stack)
		(*stack)->prev = nxt;
	*stack = nxt;
	return (nxt);
}

/**
 * print_stack - this function prints the contents of a
 * stack_t stack
 * @stack: this is the head of the stack
 * Return: the number of elements of the list
 */

size_t print_stack(const stack_t *stack)
{
	size_t sz;

	sz = 0;
	while (stack)
	{
		printf("%d\n", stack->n);
		stack = stack->next;
		sz++;
	}
	return (sz);
}

/**
 * free_stack - this function frees a dlistint_t linked list
 * @stack: this is the head of the list
 * Return: nothing
 */

void free_stack(stack_t *stack)
{
	stack_t *new;
	stack_t *loc = stack;

	if (stack)
	{
		new = stack->next;
		while (loc)
		{
			free(loc);
			loc = new;
			if (new)
				new = new->next;
		}
	}
}
