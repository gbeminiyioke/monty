#include "monty.h"

/**
 * mod - ths opcode computes the remainder of the
 * division
 * @stack: stack given by main
 * @line_num: this is the line number
 * Return: nothing
 */

void mod(stack_t **stack, unsigned int line_num)
{
	int i;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_num);
		exit(EXIT_FAILURE);
		return;
	}
	if (((*stack)->n) == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		exit(EXIT_FAILURE);
		return;
	}
	i = ((*stack)->next->n) % ((*stack)->n);
	pop(stack, line_num);
	(*stack)->n = i;
}
