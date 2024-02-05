#include "monty.h"

/**
 * execute - this function executes opcodes
 * @stack: this is the head of the linked list
 * stack.
 * @line_num: this is the line number
 * @file: this is a pointer to the monty file
 * @content: this is the content of the line
 * Return: nothing.
 */

int execute(char *content, stack_t **stack, unsigned int line_num, FILE *file)
{
	instruction_t opst[] = {
		{"push", m_push},
		{"pall", m_pall},
		{"pint", m_pint},
		{"pop", m_pop},
		{"swap", m_swap},
		{"add", m_add},
		{"nop", m_nop},
		{"sub", m_sub},
		{"div", m_div},
		{"mul", m_mul},
		{"mod", m_mod},
		{"pchar", m_pchar},
		{"pstr", m_pstr},
		{"rotl", m_rotl},
		{"rotr", m_rotr},
		{"queue", m_queue},
		{"stack", m_stack},
		{NULL, NULL}
	};

	char *c;
	unsigned int i = 0;

	i = 0;
	c = strtok(content, "\n\t");
	if (c && c[0] == '#')
		return (0);
	bus.arg = strtok(NULL, "\n\t");
	while (opst[i].opcode && c)
	{
		if (strcmp(c, opst[i].opcode) == 0)
		{
			opst[i].f(stack, line_num);
			return (0);
		}
		i++;
	}
	if (c && opst[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_num, c);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
