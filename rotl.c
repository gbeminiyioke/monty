#include "monty.h"

/**
 * rotl - this opcode rotates the first element of the stack
 * @stack: this is the head of the stack
 * @line_num: this is the line num
 * Return: nothing
 */

void rotl(stack_t **stack, unsigned int line_num)
{
	stack_t *nxt;
	stack_t *loc;

	(void) line_num;
	if (!stack || !*stack || !(*stack)->next)
		return;
	nxt = loc = *stack;
	while (loc->next)
		loc = loc->next;
	loc->next = nxt;
	nxt->prev = loc;
	*stack = nxt->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}
