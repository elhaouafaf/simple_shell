#include "main.h"
/**
 * _setenv - Entry point.
 * @key: key value.
 * @value: value.
 * @overwrite: overwrite.
 *
 * Return: Always 0.
 */
void _setenv(char *key, char *value, int overwrite)
{
	setenv(key, value, overwrite);
}
/**
 * _unsetenv - Entry point.
 * @key: key value.
 * Return: Always 0.
 */
void _unsetenv(char *key)
{
	unsetenv(key);
}
