#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stddef.h>
#include <errno.h>
#include <signal.h>
#include <fcntl.h>
#include <stdbool.h>

#define MAXIMUM_ARGUMENTS 64
#define MAXIMUM_COMMAND_LENGTH 1024
#define MAXIMUM_INPUT_SIZE 1024
#define BUFFER_SIZE 1024

#define ERROR_EXEC 1
#define DELIM ":\n\r"

extern char **environ;
void display_prompt(void);
char *custom_getline(int fd);
void read_command(char **buffer);
int main(void);
int convert_to_int(char *str);
void redirect_output(char **args);
char *find_command_in_PATH(char *command);
void signal_handling(int signal);
void interactive_shell_program(void);
void execute_piped_cmds(char *cmds[], int number_cmds);
void print_environment(void);
void parse_input(char *input, char **args, int *argCount);
bool parse_string(char *str, char delimiter);
void tokenize_input(char *input, char *args[]);
void execute_command(char *command, char *args[]);

#endif
