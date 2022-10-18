#include "main.h"

/**
 * _printfBin - prints unsigned binary number
 * @arg: the argument pointer
 * @params: the parameters struct
 *
 * Return: bytes printed
 */
int _printfBin(va_list arg, format_t *params)
{
	unsigned int n = va_arg(arg, unsigned int);
	char *str = litoa(n, 2, CONVERT_UNSIGNED, params);
	int c = 0;

	if (params->hashtag_flag && n)
		*--str = '0';
	params->unsign = 1;
	return (c += print_number(str, params));
}

/**
 * _printf_hex - prints unsigned hex numbers in lowercase
 *
 * @arg: the argument pointer
 * @params: the parameters struct
 *
 * Return: bytes printed
 */
int _printf_hex(va_list arg, format_t *params)
{
	unsigned long l;
	int c = 0;
	char *str;

	if (params->l_modifier)
		l = (unsigned long)va_arg(arg, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(arg, unsigned int);
	else
		l = (unsigned int)va_arg(arg, unsigned int);

	str = litoa(l, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	if (params->hashtag_flag && l)
	{
		*--str = 'x';
		*--str = '0';
	}
	params->unsign = 1;
	return (c += print_number(str, params));
}

/**
 * _printf_HEX - prints unsigned hex numbers in uppercase
 *
 * @arg: the argument pointer
 * @params: the parameters struct
 *
 * Return: bytes printed
 */
int _printf_HEX(va_list arg, format_t *params)
{
	unsigned long l;
	int c = 0;
	char *str;

	if (params->l_modifier)
		l = (unsigned long)va_arg(arg, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(arg, unsigned int);
	else
		l = (unsigned int)va_arg(arg, unsigned int);

	str = litoa(l, 16, CONVERT_UNSIGNED, params);
	if (params->hashtag_flag && l)
	{
		*--str = 'X';
		*--str = '0';
	}
	params->unsign = 1;
	return (c += print_number(str, params));
}

/**
 * _printf_octal - prints unsigned octal numbers
 *
 * @arg: the argument pointer
 * @params: the parameters struct
 *
 * Return: bytes printed
 */
int _printf_octal(va_list arg, format_t *params)
{
	unsigned long l;
	char *str;
	int c = 0;

	if (params->l_modifier)
		l = (unsigned long)va_arg(arg, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(arg, unsigned int);
	else
		l = (unsigned int)va_arg(arg, unsigned int);
	str = litoa(l, 8, CONVERT_UNSIGNED, params);

	if (params->hashtag_flag && l)
		*--str = '0';
	params->unsign = 1;
	return (c += print_number(str, params));
}
