#include "main.h"

/**
 * _printfUnsigned - Prints natural numbers(unsigned int).
 *
 * @args: Argument list(input number).
 * Return: Length of the number printed.
 */
int _printfUnsigned(va_list args)
{
	char *n_buff;
	int n_len;

	n_buff = litoa(va_arg(args, unsigned int), 10);
	n_len = print((n_buff == NULL) ? "(NULL)" : n_buff);

	return (n_len);
}
