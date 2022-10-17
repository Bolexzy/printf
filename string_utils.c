#include "main.h"

/**
 * _strlen - Calculate the length of a string
 *
 * @str: String
 * Return: Length
 */
int _strlen(const char *str)
{
	unsigned int i;

	for (i = 0; str[i] != '\0'; i++)
		;

	return (i);
}

/**
 * print - print char.
 *
 * @str: string.
 * Return: string length.
 */
int print(char *str)
{
	unsigned int i;

	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);

	return (i);
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
