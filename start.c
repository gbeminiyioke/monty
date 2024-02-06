#define  _POSIX_C_SOURCE 200809L
#include "monty.h"

void file_error(char *argv);
void error_usage(void);
int status = 0;

/**
 * main - this is the entry point of the program
 * @argv: list of arguments passed to our program
 * @argc: number of arguments
 * Return: nothing
 */

int main(int argc, char **argv)
{
	FILE *file;
	char *str = NULL;
	stack_t *stack = NULL;
	unsigned int ln;
	size_t bufr;
	char *buff = NULL;

	bufr = 0;
	ln = 1;
	global.data_struct = 1;
	if (argc != 2)
		error_usage();
	file = fopen(argv[1], "r");
	if (!file)
		file_error(argv[1]);
	while ((getline(&buff, &bufr, file)) != (-1))
	{
		if (status)
			break;
		if (*buff == '\n')
		{
			ln++;
			continue;
		}
		str = strtok(buff, " \t\n");
		if (!str || *str == '#')
		{
			ln++;
			continue;
		}
		global.argument = strtok(NULL, " \t\n");
		opcode(&stack, str, ln);
		ln++;
	}
	free(buff);
	free_stack(stack);
	fclose(file);
	exit(EXIT_SUCCESS);
}

/**
 * file_error - prints file error message and exits
 * @argv: argv given by main()
 * Description: print msg if  not possible to open the file
 * Return: nothing
 */

void file_error(char *argv)
{
	fprintf(stderr, "Error: Can't open file %s\n", argv);
	exit(EXIT_FAILURE);
}

/**
 * error_usage - prints usage message then exits
 * Desc: if user does not give any file or more than
 * one argument to your program
 * Return: nothing
 */

void error_usage(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
