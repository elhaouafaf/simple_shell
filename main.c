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
	char *buf = NULL;
	size_t buf_size = 0;
	signal(SIGINT, handle_interrupt);
	char *cmd, **args;
	pid_t pid;
	int status;
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
		}
		else
			exit(127);
		}
		else
		wait(&status);
	}
	free_args(args);
	}
	free(buf);
	return (0);
}
