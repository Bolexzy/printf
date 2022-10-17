#include "main.h"

/**
 * _printfHexLow - Print a number in lowercase hexadecimal fromat.
 *
 * @args: Arguments list(parsed int)
 * Return: Length of printed number.
 */
int _printfHex_Low(va_list args)
{
	char *h_buf;
	int h_len;

	h_buf = litoa(va_arg(args, unsigned int), 16);
	h_buf = str_tolower(h_buf);

	h_len = print((h_buf == NULL) ? "(NULL)" : h_buf);

	return (h_len);
}
