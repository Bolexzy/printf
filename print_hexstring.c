#include "main.h"

/**
 * hex_print - prints a char's ascii value in uppercase hex
 *
 * @c: char to print
 * Return: number of chars printed (always 2)
 */
void hex_print(char c)
{
	int len;
	char diff = 'A' - ':';
	char d[2];

	d[0] = c / 16;
	d[1] = c % 16;
	for (len = 0; len < 2; len++)
	{
		if (d[len] >= 10)
			_putchar('0' + diff + d[len]);
		else
			_putchar('0' + d[len]);
	}
}

/**
 * _printfStringHex - Printd string and some characters in hex.
 *
 * @args: Argument list(parsed string)
 * Return: The number of printed chars.
 */
int _printfStringHex(va_list args)
{
	char *s;
	int s_len;
	unsigned int i;

	s = va_arg(args, char *);

	i = 0;
	s_len = 0;
	if (s == NULL)
		s = "(NULL)";

	while (s[i] != '\0')
	{
		if (s[i] < 32 || s[i] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			s_len += 2;
			hex_print(s[i]);
			s_len += 2;
		}
		else
		{
			_putchar(s[i]);
		} i++;
	}
	s_len += i;

	return (s_len);
}
