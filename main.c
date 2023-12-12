#include "main.h"

int main(void)
{
char *command;
char **args;

while (1)
{
print_prompt();
command = read_command();
args = split_command(command);
execute_command(args[0], args);
free_memory(command, args);
}

return (0);
}
