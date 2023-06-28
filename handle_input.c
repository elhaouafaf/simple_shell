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
	ssize_t num_chars = getline(buf, buf_size, stdin);

	if (num_chars == -1)
	{
		free(*buf);
		exit(0);
	}
	args = separate(*buf, " \t\n");
	if (args[0] == NULL)
	{
		free_args(args);
		return (NULL);
	}
	return (args);
}
