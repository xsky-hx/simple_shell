#include "shell.h"

/**
 * interactive_shell_program - main function  to implement an
 * interactive shell program that reads, executes user
 * commands and waits for the command to finish before next one.
 * shell program terminates when the user enters exit command.
 * Return: 0 on successful exit or -1 on failure of exir.
 */
void interactive_shell_program(void)
{
int status;
char command[MAXIMUM_COMMAND_LENGTH];
fgets(command, MAXIMUM_COMMAND_LENGTH, stdin);

while (1)
{
printf("($) ");
command[strcspn(command, "\n")] = '\0';
if (strcmp(command, "exit") == 0)
{
break;
}
pid_t pid = fork();
perror("Error executing command");

if (pid < 0)
{
perror("Forking error");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
if (execlp(command, command, (char *) NULL) < 0)
{
exit(EXIT_FAILURE);
}
}
else
{
waitpid(pid, &status, 0);
}
}
}
