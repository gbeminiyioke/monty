#include "monty.h"

/**
 * push - this function adds a node to the stack
 * @stack: this is the head of the stack
 * @line_num: this is the line number
 * Return: nothing
 */

void push(stack_t **stack, unsigned int line_num)
{
	char *i = global.argument;

	if ((is_digit(i)) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_num);
		exit(EXIT_FAILURE);
	}
	if (global.data_struct == 1)
	{
		if (!add_node(stack, atoi(global.argument)))
		{
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (!queue_node(stack, atoi(global.argument)))
		{
			exit(EXIT_FAILURE);
		}
	}
}
