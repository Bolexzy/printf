#include "main.h"

/**
 * _printfStr - Prints string
 *
 * @args: Arguments list.
 * Return: String length.
 */
int _printfStr(va_list args)
{
	char *s;
	int s_len;

	s = va_arg(args, char *);
	s_len = print((s != NULL) ? s : "(null)");

	return (s_len);
}
