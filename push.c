#include "monty.h"

/**
 * m_push - this function adds a node to the stack
 * @head: head of the stack
 * @line_num: the line number
 * Return: nothing
 */

void m_push(stack_t **head, unsigned int line_num)
{
	int i;
	int j;
	int flag;

	j = 0;
	flag = 0;
	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			j++;
		for (; bus.arg[j] != '\0'; j++)
		{
			if (bus.arg[j] < 48 || bus.arg[j] > 57)
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_num);
			fclose(bus.file);
			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_num);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	i = atoi(bus.arg);
	if (bus.lifi == 0)
		addnode(head, i);
	else
		addqueue(head, i);
}
