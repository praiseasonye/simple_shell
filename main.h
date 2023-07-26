#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>

#define BUFFER_SIZE 1024
void handle_non_interactive_mode(int input_fd);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);

int count_commands(const char *input, const char *delim);
void execute_cmd(char **argv);
char *get_cmddir(char *cmd);
char **tokenize(char *input, const char *delim, int *num_tokens);
void (*builtin_selector(char *str))(char **str);
void double_free(char **to_be_freed);

/* define a structure to handle built-in commands */
/**
 * struct builtin_t - a structure that for calling
 *                    a builtin commmand.
 * @name: the name of the builtin command
 * @func: the function to be called.
 *
 */

typedef struct builtin_t
{
	char *name;
	void (*func)(char **argv);
} builtin_command;

/* built-in functions */
void shell_exit(char **argv);
void shell_env(char **argv);
extern char **environ;
#endif /* main.h */
