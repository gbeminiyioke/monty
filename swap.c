#include "monty.h"

/**
 * swap -  swaps data from top to previous
 * @stack: this is the head of the stack
 * @line_num: this is the line number
 * Return: nothing
 */

void swap(stack_t **stack, unsigned int line_num)
{
	int i;
	stack_t *loc = NULL;

	i = 0;
	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	loc = *stack;
	i = loc->n;
	loc->n = i;
	loc->n = loc->next->n;
	loc->next->n = i;
}
