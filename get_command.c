#include "main.h"
/**
 * get_command - Retrieves the full command path
 * @command: The command to search for
 *
 * Return: The full command path if found, otherwise NULL
 */
char *get_command(char *command)
{
	struct stat st;

	if (strchr(command, '/') != NULL)
	{
		if (stat(command, &st) == 0)
		{
			if (S_ISREG(st.st_mode) && (st.st_mode & S_IXUSR))
				return (strdup(command));
		}
	}
	else
	{
		char *path = _getenv("PATH");
		char *token;
		char *full_cmd;

		token = strtok(path, ":");
		while (token)
		{
			full_cmd = malloc(_strlen(token) + _strlen(command) + 2);
			_strcpy(full_cmd, token);
			_strcat(full_cmd, "/");
			_strcat(full_cmd, command);
			if (stat(full_cmd, &st) == 0)
				return (full_cmd);
			free(full_cmd);
			token = strtok(NULL, ":");
		}
	}
	return (NULL);
}
