#include "main.h"

/**
 * _printfInt - Prints integers.
 *
 * @args: arguments lists.
 * Return: length of the numbers in decimals.
 */
int _printfInt(va_list args)
{
	char *i_buff;
	int i_len;

	i_buff = litoa(va_arg(args, int), 10);
	i_len = print((i_buff == NULL) ? "(NULL)" : i_buff);

	return (i_len);
}
