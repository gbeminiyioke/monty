#include "monty.h"

/**
 * pall - this opcode prints the stack
 * @stack: this is the head of the stack
 * @line_num: this is the line number
 * Return: nothing
 */

void pall(stack_t **stack, unsigned int line_num __attribute__((unused)))
{
	print_stack(*stack);
}
