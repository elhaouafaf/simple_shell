#include "main.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/**
 * _strtok - Tokenizes a string by a delimiter
 * @str: The string to be tokenized
 * @delim: The delimiter used for tokenizing
 *
 * Return: A pointer to the next token, or NULL if no more tokens are found
 */
char *_strtok(char *str, const char *delim)
{
	char *token_start, *delimiter_pos;
	static char *next_token = NULL;
	bool delimiter_found = false;

	if (str != NULL)
	{
		next_token = str;
	}
	else if (next_token == NULL)
	{
		return NULL;
	}

	token_start = next_token;
	delimiter_pos = strstr(next_token, delim);
	if (delimiter_pos != NULL)
	{
		*delimiter_pos = '\0';
		next_token = delimiter_pos + strlen(delim);
		delimiter_found = true;
	}
	else if (*next_token != '\0')
	{
		next_token += strlen(next_token);
	}

	if (delimiter_found)
	{
		return token_start;
	}
	else if (*token_start != '\0')
	{
		return token_start;
	}

	return NULL;
}

