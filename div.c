#include "monty.h"

/**
 * m_div - this opcodes divides the second top
 * element of the stack by the top elememt of
 * the stack
 * @head: this is the stack head
 * @line_num: the line number
 * Reyurn: nothing.
 */

void m_div(stack_t **head, unsigned int line_num)
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
		fprintf(stderr, "L%d: can't div, stack too short\n", line_num);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	loc = *head;
	if (loc->n == 0)
	{
		fprintf(stderr, "L%: division by zero\n", line_num);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	j = loc->next->n / loc->n;
	loc->next->n = j;
	*head = loc->next;
	free(loc);
}
