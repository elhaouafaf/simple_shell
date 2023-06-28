#include "main.h"

/**
 * handle_interrupt - Signal handler for SIGINT (Ctrl+C)
 * @sig: Signal number
 *
 * Description: Handles the SIGINT signal by writing a prompt to
 * the standard
 * output.
 */

void handle_interrupt(int sig)
{
	(void)sig;
	write(1, "\n$ ", 3);
}

/**
 * execute_command - Executes the given command
 * with arguments in a child process
 * @args: Array of arguments
 * @cmd: Pointer to the command string
 * @buf: Buffer for input
 *
 * Description: Executes the command with arguments in a child process using
 * the execve system call. If the command is not found, it displays an error
 * message to the standard error output.
 */

void execute_command(char **args, char **cmd, char *buf)
{
	int status;
	pid_t pid = fork();

	if (pid == 0)
	{
		*cmd = get_command(args[0]);
		if (*cmd)
		{
			execve(*cmd, args, NULL);
			free(*cmd);
			free_args(args);
			free(buf);
			exit(0);
		}
		else
		{
			write(STDERR_FILENO, "command not found\n", 19);
			free_args(args);
			free(buf);
			free(*cmd);
			exit(127);
		}
	}
	else if (pid < 0)
	{
		write(STDERR_FILENO, "Fork failed\n", 12);
	}
	else
	{
		wait(&status);
	}
}
/**
 * main - Entry point of the program
 * Return: Always 0
 */
int main(void)
{
	char *buf = NULL;
	size_t buf_size = 0;
	char **args;
	char *cmd = NULL;

	signal(SIGINT, handle_interrupt);
	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		args = handle_input(&buf, &buf_size);
		if (args == NULL)
			continue;
		if (strcmp(args[0], "exit") == 0)
		{
			free_args(args);
			free(buf);
			exit(0);
		}
		if (strcmp(args[0], "env") == 0)
			print_env();
		else
			execute_command(args, &cmd, buf);
		free_args(args);
	}
	free(buf);
	return (0);
}
