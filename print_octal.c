#include "main.h"

/**
 * _printfOct - Print an unsigned int in octal base.
 *
 * @args: Argument list(unsigned int)
 * Return: Length of the printed int.
 */
int _printfOct(va_list args)
{
	char *o_buff;
	int o_len;

	o_buff = litoa(va_arg(args, unsigned int), 8);
	o_len = print((o_buff == NULL) ? "(NULL)" : o_buff);

	return (o_len);
}
