#include "monty.h"

/**
 * pop - this opcode removes the top element
 * of the stack
 * @stack: this is the head of the stack
 * @line_num: this is the line number
 * Return: nothing
 */

void pop(stack_t **stack, unsigned int line_num)
{
	stack_t *loc = NULL;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_num);
		exit(EXIT_FAILURE);
	}
	loc = (*stack)->next;
	free(*stack);
	*stack = loc;
	if (!*stack)
		return;
	(*stack)->prev = NULL;
}
