#include "main.h"

/**
 * _getenv - Get the value of an environment variable.
 * @env_v: The environment variable to retrieve.
 * Return: The value of the environment variable, or NULL if not found.
 */
char *_getenv(const char *env_v)
{
	int i = 0;
	char *key;

	while (environ[i])
	{
		key = strtok(environ[i], "=");
		if (_strcmp(env_v, key) == 0)
			return (strtok(NULL, "\n"));
		i++;
	}
	return (NULL);
}
