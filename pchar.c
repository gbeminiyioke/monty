#include "monty.h"

/**
 * pchar - this opcode prints the int at the top
 * of the stack as char
 * @stack: this is the head of the stack
 * @line_num: this is the line number
 * Return: nothing
 */

void pchar(stack_t **stack, unsigned int line_num)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
		exit(EXIT_FAILURE);
		return;
	}
	if (isascii((*stack)->n) == 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_num);
		exit(EXIT_FAILURE);
		return;
	}
	printf("%c\n", (*stack)->n);
}
