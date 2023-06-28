#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * separate - Tokenizes a string into an array of tokens
 * @buf: The string to be tokenized
 * @del: The delimiter used for tokenizing
 *
 * Return: An array of tokens
 */
char **separate(char *buf, char *del)
{
	char **temp;
	char **tokens = NULL;
	char *token = NULL;
	int i = 0;
	int max_tokens = 10;

	if (buf == NULL || del == NULL)
	return (NULL);

	tokens = malloc(sizeof(char *) * max_tokens);
	if (tokens == NULL)
	return (NULL);

	token = strtok(buf, del);
	while (token != NULL)
	{
	tokens[i] = token;
	i++;

	if (i >= max_tokens)
	{
	max_tokens *= 2;
	temp = realloc(tokens, sizeof(char *) * max_tokens);

	if (temp == NULL)
	{
	free(tokens);
return (NULL);
}
tokens = temp;
}

token = strtok(NULL, del);
}

tokens[i] = NULL;
return (tokens);
}
