#include "main.h"

/**
 * handler - format checker
 *
 * @format: String format.
 * @args: List of arguments.
 * Return: Total number of characters in argument and
 * number of characters in the string format.
 */
int handler(const char *format, va_list args)
{
	int size;
	format_t params = PARAMS_INIT;
	char *p, *start;

	size = 0;
	if (format[0] == '%' && !format[1])
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);

	for (p = (char *)format; *p; p++)
	{
		init_params(&params, args);
		if (*p != '%')/* check for specifier */
		{
			size += _putchar(*p);
			continue;
		}

		start = p;
		p++;
		while (handle_flag(p, &params))/* while char at p is a flag character */
		{
			p++;/* traverse */
		}
		p = handle_width(p, &params, args);
		p = handle_precision(p, &params, args);
		if (handle_modifier(p, &params))
			p++;
		if (!handle_specifier(p))
			size += print_to(start, p,
					params.l_modifier || params.h_modifier ? p - 1 : 0);
		else
			size += get_print_format(p, args, &params);
	}
	_putchar(BUF_FLUSH);
	return (size);
}

/**
 * handle_specifier - Checker for format function.
 *
 * @str: Format string.
 * Return: Size of the numbers of characters printed.
 */
int (*handle_specifier(char *str))(va_list arg, format_t *params)
{
	int i;

	specifier_t formats[] = {
		{'c', _printfChar},

		{'i', _printfInt}, {'d', _printfInt},
		{'%', print_percent}, {'s', _printfStr},
		{'b', _printfBin}, {'x', _printf_hex},
		{'X', _printf_HEX}, {'o', _printf_octal},
		{'u', _printf_unsigned}, {'S', _printf_S},
		{'p', _printf_address}, {'r',  printf_rev},
		{'R', printf_rot13}

	};

	i = 0;

	while (formats[i].flag)
	{
		if (*str == formats[i].flag)
		{
			return (formats[i].fmt);
		}
		i++;
	}
	return (NULL);
}

/**
 * get_print_format - finds the format function
 *
 * @s: string of the format
 * @arg: List of argument(parsed arg)
 * @params: the parameters struct
 * Return: the number of bytes printed
 */

int get_print_format(char *s, va_list arg, format_t *params)
{
	int (*fmt)(va_list, format_t *) = handle_specifier(s);

	if (fmt)
		return (fmt(arg, params));
	return (0);
}
