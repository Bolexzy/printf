#include "main.h"

/**
 * _isdigit - checks if character is digit
 *
 * @c: the character to check
 * Return: 1 if digit, 0 otherwise
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * litoa - Converts integer to ascii
 *
 * @num: Input integer.
 * @radix: base.
 * @flags: Argument flags
 * @params: Parameter struct
 * Return: Pointer to converted string.
 */
char *litoa(long int num, int radix, int flags, format_t *params)
{
	static char *conversion;
	static char buffer[50];
	char *ptr;
	unsigned long int n;
	char minus = 0;
	(void)params;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		minus = '-';
	}
	else
		n = (unsigned int)num;

	conversion = flags & CONVERT_LOWERCASE
		? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do {
		*--ptr = conversion[n % radix];
		n /= radix;
	} while (n != 0);

	if (minus)
		*--ptr = '-';

	return (ptr);
}