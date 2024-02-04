#include "monty.h"

/**
 * m_sub - this opcode subtracts the top element
 * of the stack from the second top element
 * @head: this is the head of the stack
 * @line_num: the line number
 * Return: nothing.
 */

void m_sub(stack_t **head, unsigned int line_num)
{
	int i;
	int j;
	stack_t *loc;

	loc = *head;
	for (j = 0; loc != NULL; j++)
		loc = loc->next;
	if (j < 2)
	{
		fprint(stderr, "L%d: can't sub, stack too short\n", line_num);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	loc = *head;
	i = loc->next->n - loc->n;
	loc->next->n = i;
	*head = loc->next;
	free(loc);
}
