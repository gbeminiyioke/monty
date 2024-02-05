#include "monty.h"

/**
 * m_swap - this opcode swaps the two top elements
 * of the stack
 * @head: this is the head of the stack
 * @line_num: the line number
 * Return: nothing.
 */

void m_swap(stack_t **head, unsigned int line_num)
{
	int i;
	int j;
	stack_t *loc;

	i = 0;
	loc = *head;
	while (loc)
	{
		loc = loc->next;
		i++;
	}
	if (i < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	loc = *head;
	j = loc->n;
	loc->n = loc->next->n;
	loc->next->n = j;
}
