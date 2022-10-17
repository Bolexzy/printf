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
	char *s_buf;
	int s_len;
	unsigned int i, tcast;

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
			tcast = s[i];
			if (tcast < 16)
			{
				_putchar ('0');
				s_len++;
			}
			s_buf = litoa(tcast, 16);
			s_len += print((s_buf == NULL) ? "(NULL)" : s_buf);
		}
		else
		{
			_putchar(s[i]);
			s_len++;
		} i++;
	}

	return (s_len);
}
