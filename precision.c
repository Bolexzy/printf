#include "main.h"

/**
 * handle_precision - gets the precision from the format string
 *
 * @s: the format string
 * @params: the parameters struct
 * @arg: the argument pointer
 * Return: new pointer
*/

char *handle_precision(char *s, format_t *params, va_list arg)
{
	int d = 0;

	if (*s != '.')
		return (s);
	s++;
	if (*s == '*')
	{
		d = va_arg(arg, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			d = d * 10 + (*s++ - '0');
	}
	params->precision = d;
	return (s);
}
