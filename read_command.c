#include "main.h"

/**
 * read_command - Read a command from standard input.
 * Return: The command entered by the user.
 */
char *read_command(void)
{
	char *buffer = NULL;
	size_t bufsize = 0;
	ssize_t chars_read;

	print_prompt();

	chars_read = getline(&buffer, &bufsize, stdin);
	if (chars_read == -1)
	{
		if (feof(stdin))
		{
			free(buffer);
			exit(EXIT_SUCCESS);
		}
		perror("getline");
		exit(EXIT_FAILURE);
	}

	return (buffer);
}
