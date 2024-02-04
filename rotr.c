#include "monty.h"

/**
 * m_rotr - this opcode rotates the stack
 * to the bottom.
 * @head: this is the head of the stack
 * @line_num: this os the line number
 * Return: nothing.
 */

void m_rotr(stack_t **head, __attribute__((used)) unsigned int line_num)
{
	stack_t *cpd;

	cpd = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (cpd->next)
	{
		cpd = cpd-next;
	}
	cpd->next = *head;
	cpd->prev->next = NULL;
	cpd->prev = NULL;
	(*head)->prev = cpd;
	(*head) = cpd;
}
