#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <ctype.h>
#include <sys/types.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct bus_s - variables -arg, line content, file
 * @arg: value
 * @file: pointer to the monty file
 * @content: the content of the line
 * @lifi: flag change stack queue
 *
 * Description: it carries value through the program
 */

typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
} bus_t;
extern bus_t bus;

void m_push(stack_t **head, unsigned int number);
void m_pall(stack_t **head, unsigned int number);
void m_pint(stack_t **head, unsigned int number);
void m_pop(stack_t **head, unsigned int line_num);
void free_stack(stack_t *head);
void m_swap(stack_t **head, unsigned int line_num);
void m_add(stack_t **head, unsigned int line_num);
void m_sub(stack_t **head, unsigned int line_num);
void m_div(stack_t **head, unsigned int line_num);
void m_mul(stack_t **head, unsigned int line_num);
void m_mod(stack_t **head, unsigned int line_num);
void m_nop(stack_t **head, unsigned int line_num);
void m_pchar(stack_t **head, unsigned int line_num);
void m_pstr(stack_t **head, unsigned int line_num);
void m_rotl(stack_t **head, unsigned int line_num);
void m_rotr(stack_t **head, __attribute__((unused)) unsigned int line_num);
void addnode(stack_t **head, int n);
void addqueue(stack_t **head, int n);
void m_stack(stack_t **head, unsigned int line_num);
void m_queue(stack_t **head, unsigned int line_num);
int execute(char *content, stack_t **head, unsigned int line_num, FILE *file);
char *_realloc(char *ptr, unsigned int o_size, unsigned int n_size);
char *clear_line(char *content);
ssize_t getstdin(char **lineptr, int file);

#endif
