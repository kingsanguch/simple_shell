#include "main.h"

/**
 * split_command - Split a command into an array of arguments.
 * @command: The command to split.
 * Return: An array of arguments.
 */
char **split_command(char *command)
{
	char **args = NULL;
	char *token;
	int i = 0;

	args = malloc(sizeof(char *) * 2); /* Assuming no more than one argument */
	if (args == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	token = strtok(command, " \n");
	while (token != NULL)
	{
		args[i] = token;
		i++;
		args = realloc(args, sizeof(char *) * (i + 2));
		if (args == NULL)
		{
			perror("realloc");
			exit(EXIT_FAILURE);
		}
		token = strtok(NULL, " \n");
	}

	args[i] = NULL; /* Null-terminate the array */

	return (args);
}
