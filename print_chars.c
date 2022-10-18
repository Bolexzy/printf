#include "main.h"

/**
 * _printfChar - print char
 *
 * @args: Arguments list
 * Return: 1(size of char).
 */
int _printfChar(va_list args)
{
	int c;

	c = va_arg(args, int);

	_putchar(c);
	return (1);
}

/**
 * _printfStr - prints string
 *
 * @arg: argument pointer
 * @params: the parameters struct
 * Return: number chars printed
 */
int _printfStr(va_list arg, format_t *params)
{
	char *str = va_arg(arg, char *), sp = ' ';
	unsigned int pad = 0, len = 0, i = 0, j;

	(void)params;
	switch ((int)(!str))
		case 1:
			str = NULL_STRING;

	j = pad = _strlen(str);
	if (params->precision < pad)
		j = pad = params->precision;

	if (params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				len += _putchar(*str++);
		else
			len += _puts(str);
	}
	while (j++ < params->width)
		len += _putchar(sp);
	if (!params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				len += _putchar(*str++);
		else
			len += _puts(str);
	}
	return (len);
}
