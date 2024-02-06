#include "monty.h"

/**
 * _mul - this opcode divides the next top value
 * by the top value
 * @stack: this is the head of the stack
 * @line_num: this is the line number
 * Return: nothing
 */

void _mul(stack_t **stack, unsigned int line_num)
{
	int i;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_num);
		exit(EXIT_FAILURE);
		return;
	}
	i = ((*stack)->next->n) * ((*stack)->n);
	pop(stack, line_num);
	(*stack)->n = i;
}
