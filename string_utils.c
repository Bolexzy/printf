#include "main.h"

/**
 * _strlen - Calculate the length of a string
 *
 * @str: String
 * Return: Length
 */
int _strlen(char *str)
{
	unsigned int i;

	for (i = 0; str[i] != '\0'; i++)
		;

	return (i);
}

/**
 * print_to - print a range of char addresses.
 *
 * @start: starting address
 * @stop: stopping address
 * @except: except address
 *
 * Return: Length of chars(byte) printed.
 */
int print_to(char *start, char *stop, char *except)
{
	int len = 0;

	while (start <= stop)
	{
		if (start != except)
			len += _putchar(*start);
		start++;
	}
	return (len);
}

/**
 * str_tolower - Checks if string is uppercase and
 * changes the string to lowercase.
 *
 * @s: The string.
 * Return: Lowercase string.
 */
char *str_tolower(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] >= 65 && s[i] <= 90)
		{
			s[i] = s[i] + 32;
		} i++;
	}

	return (s);
}

/**
 * _strcmp - Compare two strings
 *
 * @s1: String 1
 * @s2: String 2
 * Return: Integer
 **/
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}

	return (0);
}

/**
 * print_percent - prints string
 *
 * @arg: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
 */
int print_percent(va_list arg, format_t *params)
{
	(void)arg;
	(void)params;
	return (_putchar('%'));
}
