#include "main.h"
/**
 * _strdup - Duplicates a string.
 * @str: The string to duplicate.
 *
 * Return: A pointer to the duplicated string, or NULL if insufficient memory
 *         is available.
 */
char *_strdup(const char *str)
{
	size_t len;
	char *new_str;

	if (str == NULL)
		return (NULL);

	len = _strlen(str) + 1;
	new_str = malloc(len);
	if (new_str == NULL)
		return (NULL);

	memcpy(new_str, str, len);
	return (new_str);
}
