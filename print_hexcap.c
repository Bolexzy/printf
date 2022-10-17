#include "main.h"

/**
 * _printfHex_Cap - Print a number in Uppercase hexadecimal fromat.
 *
 * @args: Arguments list(parsed int)
 * Return: Length of number printed.
 */
int _printfHex_Cap(va_list args)
{
	char *h_buf;
	int h_len;

	h_buf = litoa(va_arg(args, unsigned int), 16);
	h_len = print((h_buf == NULL) ? "(NULL)" : h_buf);

	return (h_len);
}
