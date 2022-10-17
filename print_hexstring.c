#include "main.h"

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
	int i, si;
	char *buff;

	s = va_arg(args, char *);

	i = 0;
	s_len = 0;
	while (s[i++] != '\0')
	{
		if (s[i] < 32 || s[i] >= 127)
		{
			_putchar(92);
			_putchar('x');
			s_len += 2;
			si = _atoi(s + i);
			buff = litoa((unsigned int)si, 16);
			s_len += print((buff == NULL) ? "(NULL)" : buff);
		}
		else
		{
			_putchar(s[i]);
			s_len++;
		}
	}
	s_len += i;

	return (s_len);
}
