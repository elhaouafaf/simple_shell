#include "main.h"

/**
 * handle_interrupt - Signal handler for SIGINT (Ctrl+C)
 * @sig: Signal number
 */
void handle_interrupt(int sig)
{
	(void)sig;
	write(1,"\n$ ", 3);
}
/**
 * execute_command - Executes a command
 * @args: Command and arguments
 */
void execute_command(char **args)
{
	char *cmd = get_command(args[0]);

	if (cmd)
	{
	execve(cmd, args, NULL);
	free(cmd);
	exit(0);
	}
	else
	{
	write(2, "command not found\n", 19);
	free_args(args);
	exit(127);
	}
}
/**
 * main - Entry point of the progra
 * This function serves as the entry point of the program. It initializes
 * variables, sets up signal handlers, and starts the main exe.
 * Return: Always 0
 */
int main(void)
{
	int status;
	char *buf, **args;
	size_t buf_size;
	pid_t pid;

	buf = NULL;
	buf_size = 0;

	signal(SIGINT, handle_interrupt);
	while (1)
	{
	write(STDOUT_FILENO, "$ ", 2);
	args = handle_input(&buf, &buf_size);
	if (strcmp(args[0], "env") == 0)
	print_env();
	else
	{
	pid = fork();
	if (pid == 0)
	{
		execute_command(args);
	}
		else
	{
		wait(&status);
	}
	}
	free(buf);
	buf = NULL;
	free_args(args);
	}
	return (0);
}
