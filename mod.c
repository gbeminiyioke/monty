#include "monty.h"

/**
 * m_mod - this opcode  computes the rest of the
 * division of the second top element of the stack
 * by the top element of the stack.
 * @head: this is the head of tbe stack
 * @line_num: this is the line number
 * Return: nothing.
 */

void m_mod(stack_t **head, unsigned int line_num)
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_num);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	loc = *head;
	if (loc->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	j = loc->next->n % loc->n;
	loc->next->n = j;
	*head = loc->next;
	free(loc);
}
