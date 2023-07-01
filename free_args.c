#include "main.h"
/**
 * free_args - Frees the memory allocated for an array of string arguments
 * @args: The array of string arguments
 */
void free_args(char **args)
{
	int i = 0;

	while (args[i])
	{
		i++;
	}
	free(args);
}
