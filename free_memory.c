#include "main.h"

/**
 * free_memory - Free memory allocated for command and arguments.
 * @command: The command string.
 * @args: The array of arguments.
 */
void free_memory(char *command, char **args)
{
	free(command);
	free(args);
}
