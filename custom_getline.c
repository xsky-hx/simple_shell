#include "shell.h"

/**
 * custom_getline - this is the main function that reads a line from
 * file descriptor.
 * @fd: file descriptor.
 * Return: return to pointer to a string contain line read
 * from file descriptor, otherwise NULL if an error occurred.
 */
char *custom_getline(int fd)
{
int z = 0;
char character;
char *line = malloc(sizeof(char) * BUFFER_SIZE);

static int max_index;
static int current_index;
static char buffer[BUFFER_SIZE];

if (!line)
return (NULL);
while (1)
{
if (current_index >= max_index)
{
int count = read(fd, buffer, BUFFER_SIZE);

max_index = count;

if (count <= 0)
{
free(line);
return (NULL);
}
}
current_index = 0;
character = buffer[current_index++];
line[z++] = character;

if (character == '\n')
{
line[z] = '\0';
return (line);
}
}
}
