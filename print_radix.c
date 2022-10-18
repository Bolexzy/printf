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
