#include "main.h"

/**
 * execute_builtin - Execute a built-in command.
 * @command: The built-in command to execute.
 * @args: The array of arguments.
 * Return: 1 if the command is a built-in, 0 otherwise.
 */
int execute_builtin(char *command, char **args)
{
if (strcmp(command, "exit") == 0)
{
/* Handle the exit built-in */
if (args[1] != NULL)
{
fprintf(stderr, "exit: too many arguments\n");
return (1);
}
exit_shell(0);
return (1);
}
else if (strcmp(command, "env") == 0)
{
/* Handle the env built-in */
env_shell();
return (1);
}
return (0);
}
