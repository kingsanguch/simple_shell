#include "main.h"

/**
 * execute_command - Execute the given command.
 * @command: The command to execute.
 * Return: 0 on success, -1 on failure.
 */
int execute_command(char *command)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (-1);
	}

	if (pid == 0)
	{
		/* Child process */
		if (execve(command, NULL, environ) == -1)
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
