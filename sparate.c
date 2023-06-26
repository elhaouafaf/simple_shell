#include "main.h"
/**
 * separate - Tokenizes a string into an array of tokens
 * @buf: The string to be tokenized
 * @del: The delimiter used for tokenizing
 *
 * Return: An array of tokens
 */
char **separate(char *buf, char *del)
{
	char **tokens;
	char *token;
	int i = 0;

	tokens = malloc(sizeof(char *) * 1024);
	token = strtok(buf, del);
	while (token)
	{
		tokens[i] = token;
		token = strtok(NULL, del);
		i++;
	}
	tokens[i] = NULL;
	return (tokens);
}
