#include "monty.h"

/**
 * _sub -  this opcode substracts the top element
 * of the stack from the second top element
 * @stack: this is the head of the stack
 * @line_num: this is the line number
 * Return: nothing
 */

void _sub(stack_t **stack, unsigned int line_num)
{
	int i;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	i = ((*stack)->next->n) - ((*stack)->n);
	pop(stack, line_num);
	(*stack)->n = i;
}
