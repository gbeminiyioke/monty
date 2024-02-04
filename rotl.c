#include "monty.h"

/**
 * m_rotl - this opcode rotates the stack to the top
 * @head: this is the head of the stack
 * @line_num: this is the line number
 * Return: nothing.
 */

void m_rotl(stack_t **head, __attribute__((unused)) unsigned int line_num)
{
	stack_t *nxt;
	stack_t *loc = *head;

	if(*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	nxt = (*head)->next;
	nxt->prev = NULL;
	while (loc->next != NULL)
	{
		loc = loc->next;
	}
	loc->next = *head;
	(*head)->next = NULL;
	(*head)->prev = loc;
	(*head) = nxt;
}
