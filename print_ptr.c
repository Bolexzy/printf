#include "main.h"


int _strcmp(char *, char *);

/**
 * _printfPtr - Print a number in hexadecimal format.
 *
 * @args: Argument list(parsed int)
 * Return: Length of number printed
 */
int _printfPtr(va_list args)
{
	char *p_buf;
	int p_len;

	p_buf = litoa(va_arg(args, unsigned long int), 16);
	p_buf = str_tolower(p_buf);

	if (!_strcmp(p_buf, "0"))
		return (print("(nil)"));

	p_len = print("0x");

	if (!_strcmp(p_buf, "-1"))
		p_len += print("ffffffffffffffff");
	else
		p_len += print(p_buf);

	return (p_len);
}
