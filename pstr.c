#include "monty.h"

/**
 * m_pstr - thos opcode prints the string starting
 * at the top of the stack, followed by a new line.
 * @head: this is the head of the stack
 * @line_num: this is the line number
 * Return: nothing.
 */

void m_pstr(stack_t **head, unsigned int line_num)
{
	stack_t *loc;
	(void)line_num;

	loc = *head;
	while (loc)
	{
		if (loc->n <= 0 || loc->n > 127)
		{
			break;
		}
		primtf("%c", loc->n);
		loc = loc->next;
	}
	printf("\n");
}
