#include "main.h"

char **handle_input(char **buf, size_t *buf_size)
{
    int num_chars = getline(buf, buf_size, stdin);
    if (num_chars == -1)
    {
        free(*buf);
        exit(0);
    }
    char **args = separate(*buf, " \t\n");
    if (strcmp(args[0], "exit") == 0)
    {
        free_args(args);
        free(*buf);
        exit(0);
    }
    return args;
}