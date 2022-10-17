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
	int p_len, a;
	void *p;

	p = va_arg(args, void *);

	if (p == NULL)
		return (print("(nil)"));

	a = (unsigned long int)p;
	p_buf = litoa(a, 16);
	p_buf = str_tolower(p_buf);

	p_len = print("0x");

	if (!_strcmp(p_buf, "-1"))
		p_len += print("ffffffffffffffff");
	else 
		p_len += print(p_buf);

	return (p_len);
}
