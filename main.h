#ifndef MAIN_H
#define MAIN_H

/* Standard Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
#include <string.h>
#include <errno.h>

/* Function Declarations */
int execute_command(char *command, char **args);
void print_prompt(void);
char *read_command(void);
char **split_command(char *command);
void free_memory(char *command, char **args);
void exit_shell(int status);
int execute_builtin(char *command, char **args);
void env_shell(void);

extern char **environ;
#endif /* MAIN_H */
