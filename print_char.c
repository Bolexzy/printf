#include "main.h"

/**
 * _printfChar - print char
 *
 * @args: Arguments list
 * Return: 1(size of char).
 */
int _printfChar(va_list args)
{
	int c;

	c = va_arg(args, int);

	_putchar(c);
	return (1);
}
