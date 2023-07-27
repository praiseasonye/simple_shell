#include "main.h"

/**
 * builtin_selector - a function that returns a pointer to a
 *                    builtin shell function.
 *
 * @str: the command that determines what builtin function to return
 *
 * Return: a poinetr to a function
 *
 */

void (*builtin_selector(char *str))(char *str)
{
	int i;

	builtin_t builtins[] = {
		{"exit", exit_b},
		{"env", env_b},
		{"cd", cd_b},
		{NULL, NULL}
	};

		/* check if the command is a built-in command*/
		for (i = 0; builtins[i].name != NULL; i++)
		{
			if (_strcmp(str, builtins[i].name) == 0)
			{
				return (builtins[i].f);
			}
		}
		return (NULL);
}
