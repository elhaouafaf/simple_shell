#include "main.h"
/**
 * handle_input - Handles user input and performs necessary operations
 * @buf: Pointer to the input buffer
 * @buf_size: Pointer to the size of the buffer
 * Return: The array of arguments obtained from the input
 */
char **handle_input(char **buf, size_t *buf_size)
{
	char **args;
	int num_chars = getline(buf, buf_size, stdin);

	if (num_chars == -1)
	{
	free(*buf);
	exit(0);
	}
	args = separate(*buf, " \t\n");

	if (_strcmp(args[0], "exit") == 0)
	{
	free_args(args);
	free(*buf);
	exit(0);
	}
	return (args);
}

