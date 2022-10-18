#include "main.h"

/**
 * _printfChar - prints character
 *
 * @arg: Arguments list(parsed int)
 * @params: the parameters struct.
 *
 * Return: (size of char printed).
 */
int _printfChar(va_list arg, format_t *params)
{
	char sp = ' ';
	unsigned int pad = 1, len = 0, ch = va_arg(arg, int);

	if (params->minus_flag)
		len += _putchar(ch);
	while (pad++ < params->width)
		len += _putchar(sp);
	if (!params->minus_flag)
		len += _putchar(ch);
	return (len);
}
