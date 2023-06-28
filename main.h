#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>

extern char **environ;

char *get_command(char *command);
char *_getenv(const char *env_v);
char **separate(char *buf, char *del);
void print_env(void);
int _strcmp(const char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_strchr(char *s, char c);
int _strlen(char *s);
int _putchar(char c);
void handle_interrupt(int sig);
char **handle_input(char **buf, size_t *buf_size);
void free_args(char **args);
void execute_command(char **args, char **cmd, char *buf);
void handle_command(char **args);

#endif
