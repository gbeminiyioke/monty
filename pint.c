#include "monty.h"

/**
 * pint - this opcode prints the value at the top
 * of the stack followed by a new line
 * @stack: this is the head of the stack
 * @line_num: this is the line number
 * Return: nothing
 */

void pint(stack_t **stack, unsigned int line_num)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
