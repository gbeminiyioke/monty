#include "monty.h"

/**
 * rotr - this opcode rotates the stack
 * @stack: this is the head of the stack
 * @line_num: thisi sthe line number
 * Return: nothing
 */

void rotr(stack_t **stack, unsigned int line_num)
{
	stack_t *bfr;
	stack_t *cpd;

	(void) line_count;
	if (!stack || !*stack || !(*stack)->next)
		return;
	cpd = *stack;
	while (cpd->next)
		cpd = cpd->next;
	bfr = cpd->prev;
	cpd->next = *stack;
	cpd->prev = NULL;
	bfr->next = NULL;
	(*stack)->prev = cpd;
	*stack = cpd;
}
