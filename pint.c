#include "monty.h"

/**
 * m_pint - this opcode prints the value at the top
 * of the stack followed by a new line
 * @head: this is the head of the stack
 * @line_num: this is the line number
 * Return: nothing.
 */

void m_pint(stack_t **head, unsigned int line_num)
{
	of (*head == NULL)
	{
		printf(stderr, "L%u: can't pint, stack empty\n", line_num);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
