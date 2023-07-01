#include "main.h"
/**
 * free_args_buf - Frees the memory allocated for an array of string arguments
 * and buffer
 * @args: The array of string arguments
 * @buf: The buffer
 */
void free_args_buf(char **args, char *buf)
{
	free_args(args);
	free(buf);
}
