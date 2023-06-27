#include "main.h"
/**
 * handle_interrupt - Signal handler for SIGINT (Ctrl+C)
 * @sig: Signal number
 */
void handle_interrupt(int sig)
{
	char *buf = NULL;
	(void)sig;

	if (buf != NULL)
		free(buf);
	exit(0);
}
/**
 * main - Entry point of the program
 * Return: Always 0
 */

int main(void)
{
	int status;
	char *buf, *cmd, **args;
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
	cmd = get_command(args[0]);
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
	free(buf);
	exit(127);
	}
	}
		else
		wait(&status);
	}
	free(buf);
	buf = NULL;
	free_args(args);
	}
	return (0);
}

