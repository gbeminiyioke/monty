#include "monty.h"

/**
 * is_digit - this function checks if a string
 * or a digit is passed
 * @string: string to check
 * Return: 1 if success, 0 if not
 */

int is_digit(char *string)
{
	if (!string || *string == '\0')
		return (0);
	if (*string == '-')
		string++;
	while (*string)
	{
		if (isdigit(*string) == 0)
			return (0);
		string++;
	}
	return (1);
}

/**
 * isnumber - this function checks if a string is a number
 * @str: the string to check
 * Return: 1 if its a number, else, 0.
 */

int isnumber(char *str)
{
	int i;

	if (!str)
		return (0);
	for (i = 0; str[i]; i++)
		if (i < '0' || i > '9')
			return (0);
	return (1);
}
