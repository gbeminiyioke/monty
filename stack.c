#include "monty.h"

/**
 * m_stack - this opcode sets the format of the
 * data to a stack (LIFO). This is the default
 * behavior of the program.
 * @head: this is the head of the stack
 * @line_num: tbis is the line number
 * Return: nothing.
 */

void m_stack(stack_t **head, unsigned int line_num)
{
	(void)head;
	(void)line_num;
	bus.lifi = 0;
}
