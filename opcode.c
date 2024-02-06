#include "./monty.h"

/**
 * opcode - this function runs all the builtins
 * @stack: this is the head of the stack
 * @str: this is the string to be compared
 * @line_num: this is the line number
 * Return: nothing
 */

void opcode(stack_t **stack, char *str, unsigned int line_num)
{
	int loc;
	instruction_t op[] = INSTRUCTIONS;

	loc = 0;
	if (!strcmp(str, "stack"))
	{
		global.data_struct = 1;
		return;
	}
	if (!strcmp(str, "queue"))
	{
		global.data_struct = 0;
		return;
	}
	while (op[loc].opcode)
	{
		if (strcmp(op[loc].opcode, str) == 0)
		{
			op[loc].f(stack, line_num);
			return;
		}
		loc++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_num, str);
	exit(EXIT_FAILURE);
}
