#include "main.h"

int specifier_handler(const char *str, va_list args, int *index);

/**
 * handler - format checker
 *
 * @str: String format.
 * @args: List of arguments.
 * Return: Total number of characters in argument and
 * number of characters in the string format.
 */
int handler(const char *str, va_list args)
{
	int size, i, traverse;

	size = 0;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '%')
		{
			traverse = specifier_handler(str, args, &i);
			if (traverse == -1)
				return (-1);

			size += traverse;
			continue;
		}

		_putchar(str[i]);
		size += 1;
	}

	return (size);
}

/**
 * specifier_handler - Checker for percent format.
 *
 * @str: Format string.
 * @args: List of arguments.
 * @index: Traversed index
 *
 * Return: Size of the numbers of characters printed.
 */
int specifier_handler(const char *str, va_list args, int *index)
{
	int size, j;
	format formats[] = {
		{'s', _printfStr}, {'c', _printfChar},
		{'i', _printfInt}, {'d', _printfInt}
	};

	*index = *index +  1;

	if (str[*index] == '\0')
		return (-1);

	if (str[*index] == '%')
	{
		_putchar('%');
		return (1);
	}

	j = 0;
	while (formats[j].flag)
	{
		if (str[*index] == formats[j].flag)
		{
			size = formats[j].fmt(args);
			return (size);
		}
		j++;
	}

	_putchar('%'), _putchar(str[*index]);

	return (2);
}
