#include "monty.h"

/**
 * m_pchar - this opcode prints the char at the
 * top of the stack, followed by a new line.
 * @head: this is the head of the stack
 * @line_num: this is the line number
 * Return: nothing
 */

void m_pchar(stack_t **head, unsigned int line_num)
{
	stack_t *loc;

	loc = *head;
	if (!loc)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (loc->n < 0 || loc->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_num);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", loc->n);
}
