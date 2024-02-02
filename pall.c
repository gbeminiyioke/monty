#include "monty.h"

/**
 * m_pall - this function prints the stack
 * @head: this is the stack head
 * @line_num: the line number
 * Return: nothing
 */

void m_pall(stack_t **head, unsigned int line_num)
{
	stack_t *loc;
	(void)line_num;

	loc = *head;
	if (loc == NULL)
		return;
	while (loc)
	{
		fprintf("%d\n", loc->n);
		loc = loc->next;
	}
}
