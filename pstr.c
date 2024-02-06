#include "monty.h"

/**
 * pstr - this opcode prints the string starting
 * at the top of the stack, followed by a new line
 * @stack: this is the head of the stack
 * @line_num: this is the line number
 * Return: nothing
 */

void pstr(stack_t **stack, unsigned int line_num __attribute__((unused)))
{
	stack_t *loc = *stack;

	while (loc)
	{
		if (loc->n <= 0 || loc->n > 127)
		{
			break;
		}
		putchar((char) loc->n);
		loc = loc->next;
	}
	putchar('\n');
}
