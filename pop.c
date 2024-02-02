#include "monty.h"

/**
 * m_pop - this opcode removes the top element of
 * the stack
 * @head: this is the head of the stack
 * @line_num: the line number
 * Return: nothing
 */

void m_pop(stack_t **head, unsigned int line_num)
{
	stack_t *loc;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an emptystack\n", line_num);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = h->next;
	free(h);
}
