#include "monty.h"
bus_t bus = {NULL, NULL, NULL, 0};

/**
 * main - this is the monty codes interpreter
 * @argc: the number of arguments supplied
 * @argv: monty file location
 * Return: 0 on success.
 */

int main(int argc, char *argv[])
{
	unsigned int cnt;
	FILE *file;
	char *details;
	size_t sz;
	stack_t *stack = NULL;
	ssize_t read_details;

	sz = 0;
	read_details = 1;
	cnt = 0;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	bus.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read_details > 0)
	{
		details = NULL;
		read_details = getline(&details, &sz, file);
		bus.content = details;
		details++;
		if (read_details > 0)
		{
			execute(details, &stack, cnt, file);
		}
		free(details);
	}
	free_stack(stack);
	fclose(file);
	return (0);
}
