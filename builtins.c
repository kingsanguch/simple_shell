#include "main.h"

/**
 * exit_shell - Exit the shell.
 * @status: The exit status.
 */
void exit_shell(int status)
{
free_memory(NULL, NULL); /* Free allocated memory */

exit(status);
}
void env_shell(void)
{
int i = 0;
char **env;

for (env = environ; *env != NULL; env++)
{
printf("%s\n", *env);
}
}
