#include "monty.h"

/**
 * m_mul - this opcode multiplies the second top
 * element of the stack by the top element
 * @head: the head of the stack
 * Return: nothin
 */

void m_mul(stack_t **head, unsigned int line_num)
{
	int i;
	int j;
	stack_t *loc;

	i = 0;
	loc = *head;
	while (loc)
	{
		loc = loc-next;
		i++;
	}
	if (i < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_num);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	loc = *head;
	j = loc->next->n * loc->n;
	loc->next->n = j;
	*head = loc->next;
	free(loc);
}
