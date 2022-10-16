#include "main.h"

/**
 * _printfBin - Print an unsigned int in base 2.
 *
 * @args: Argument list(unsigned int)
 * Return: Length og binary numbers printed.
 */
int _printfBin(va_list args)
{
	char *bin_buff;
	int bin_len;

	bin_buff = litoa(va_arg(args, int), 2);
	bin_len = print(bin_buff);

	return (bin_len);
}
