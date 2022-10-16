#include "main.h"

/**
 * _putchar - writes the character c to stdout
 *
 * @c: The character to print
 * Return: standard ouput
 */
int _putchar(char c)
{
	return (buffer(c));
}

/**
 * buffer - Store the character in a buffer.
 * @c: Character
 *
 * Return: 1
 */
int buffer(char c)
{
	static char buffer[1024];
	static char i;

	if (c == -1 || i = 1024)
	{
		write(1, buffer, i);
		i = 0;
	}

	if (c != -1)
		buffer[i++] = c;

	return (1);
}
