#include "main.h"

/**
 * _printfChar - print char
 *
 * @arg: Arguments list
 * @params: the parameters struct
 * Return: 1(size of char).
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

/**
 * _printf_S - custom format specifier
 *
 * @arg: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
 */
int _printf_S(va_list arg, format_t *params)
{
	char *str = va_arg(arg, char *);
	char *hex;
	int count = 0;

	if ((int)(!str))
		return (_puts(NULL_STRING));
	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			count += _putchar('\\');
			count += _putchar('x');
			hex = litoa(*str, 16, 0, params);
			if (!hex[1])
				count += _putchar('0');
			count += _puts(hex);
		}
		else
		{
			count += _putchar(*str);
		}
	}
	return (count);
}

/**
 * printf_rev - prints string in reverse
 * @arg: string
 * @params: the parameters struct
 *
 * Return: number bytes printed
 */

int printf_rev(va_list arg, format_t *params)
{
	int len, count = 0;
	char *str = va_arg(arg, char *);
	(void)params;

	if (str)
	{
		for (len = 0; *str; str++)
			len++;
		str--;
		for (; len > 0; len--, str--)
			count += _putchar(*str);
	}
	return (count);
}

/**
 * printf_rot13 - prints string in rot13
 * @arg: string
 * @params: the parameters struct
 *
 * Return: number bytes printed
 */
int printf_rot13(va_list arg, format_t *params)
{
	int i, index;
	int count = 0;
	char arr[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(arg, char *);
	(void)params;

	i = 0;
	index = 0;
	while (a[i])
	{
		if ((a[i] >= 'A' && a[i] <= 'Z')
		    || (a[i] >= 'a' && a[i] <= 'z'))
		{
			index = a[i] - 65;
			count += _putchar(arr[index]);
		}
		else
			count += _putchar(a[i]);
		i++;
	}
	return (count);
}
