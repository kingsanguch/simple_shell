#include "main.h"
#include <unistd.h>

/**
 * execute_command - Execute the given command.
 * @command: The command to execute.
 * @args: argument
 * Return: 0 on success, -1 on failure.
 */
int execute_command(char *command, char **args)
{
	pid_t pid;
	int status;
if (execute_builtin(command, args))
return (0);
   /*ceck if the command exists in PATH */
if (access(command, F_OK) == -1)
{
fprintf(stderr, "%s: command not found\n", command);
return (-1);
}

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (-1);
	}

	if (pid == 0)
	{
		/* Child process */
		if (execve(command, args, env) == -1)
		{
			perror("execve");
			_exit(EXIT_FAILURE);
		}
	}
	else
	{
		/* Parent process */
		waitpid(pid, &status, 0);
		return (0);
	}

	return (-1); /* Shouldn't reach here */
}
