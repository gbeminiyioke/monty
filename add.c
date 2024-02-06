#include "monty.h"

/**
 * _add -  adds the first two nodes of the stack
 * @stack: stack given by main
 * @line_num: this is the line number
 * Return: nothing
 */

void _add(stack_t **stack, unsigned int line_num)
{
	int i;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	i = ((*stack)->next->n) + ((*stack)->n);
	pop(stack, line_num);
	(*stack)->n = i;
}
