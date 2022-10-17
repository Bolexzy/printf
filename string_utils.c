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


int _atoi(char *s)
{
	int sign = 1;
	unsigned int num = 0;

	do {
		if (*s == '-')
			sign *= -1;

		else if (*s >= '0' && *s <= '9')
			num = (num * 10) + (*s - '0');

		else if (num > 0)
			break;

	} while (*s++);

	return (num * sign);
}
