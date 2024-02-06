#include "monty.h"

/**
 * _div - this opcodes divides the second top
 * element of the stack by the top elememt of
 * the stack
 * @stack: stack given by main
 * @line_num: this is the line number
 * Return: nothing
 */

void _div(stack_t **stack, unsigned int line_num)
{
	int i;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	if (((*stack)->n) == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num;
		exit(EXIT_FAILURE);
		;
		return;
	}
	i = ((*stack)->next->n) / ((*stack)->n);
	pop(stack, line_num);
	(*stack)->n = i;
}
