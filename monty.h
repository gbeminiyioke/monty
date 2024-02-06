#ifndef MONTY_H
#define MONTY_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define INSTRUCTIONS              \
		{			\
			{"push", push},   \
			{"pall", pall},   \
			{"pint", pint},   \
			{"pop", pop},     \
			{"swap", swap},   \
			{"nop", nop},     \
			{"div", _div},    \
			{"mul", _mul},    \
			{"add", _add},    \
			{"sub", _sub},    \
			{"mod", mod},     \
			{"pchar", pchar}, \
			{"pstr", pstr},   \
			{"rotl", rotl},   \
			{"rotr", rotr},   \
			{                     \
				NULL, NULL      \
			}                     \
		}

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 *  @n: integer
 *  @prev: points to the previous element of the stack (or queue)
 *  @next: points to the next element of the stack (or queue)
 *  Description: doubly linked list node structure
 *  for stack, queues, LIFO, FIFO
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct help - argument for the current opcode
 * @data_struct: stack mode, stack (default) and queue
 * @argument: the arguments of the string
 * Description: global structure used to pass data around the functions easily
 */

typedef struct help
{
	int data_struct;
	char *argument;
} help;
help global;

void opcode(stack_t **stack, char *str, unsigned int line_num);
int isnumber(char *str);
int is_digit(char *string);
void rotl(stack_t **stack, unsigned int line_num);
void rotr(stack_t **stack, unsigned int line_num);
void pchar(stack_t **stack, unsigned int line_num);
void pstr(stack_t **stack, unsigned int line_num);
void _add(stack_t **stack, unsigned int line_num);
void _sub(stack_t **stack, unsigned int line_num);
void _mul(stack_t **stack, unsigned int line_num);
void mod(stack_t **stack, unsigned int line_num);
void _div(stack_t **stack, unsigned int line_num);
void pint(stack_t **stack, unsigned int line_num);
void swap(stack_t **stack, unsigned int line_num);
void push(stack_t **stack, unsigned int line_num);
void pall(stack_t **stack, unsigned int line_num);
void pop(stack_t **stack, unsigned int line_num);
void nop(stack_t **stack, unsigned int line_num);
stack_t *queue_node(stack_t **stack, const int n);
stack_t *add_node(stack_t **stack, const int n);
void free_stack(stack_t *stack);
size_t print_stack(const stack_t *stack);

#endif
