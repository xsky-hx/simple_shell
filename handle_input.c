#include "shell.h"

/**
 * convert_to_int - this is main function that converts
 * string to integer and returns it.
 *
 * @str:  A converted string input into an integer.
 *
 * Return: Integer value of input string.
 */
int convert_to_int(char *str)
{
int number = atoi(str);

if (number == 0 && str[0] != '0')
{
fprintf(stderr, "Invalid integer: %s\n", str);
exit(1);
}
return (number);
}
