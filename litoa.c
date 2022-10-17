#include "main.h"

/**
 * litoa - Converts integer to ascii
 *
 * @num: Input integer.
 * @radix: base.
 * Return: Pointer to converted string.
 */
char *litoa(long int num, int radix)
{
	static char *figurative = "0123456789ABCDEF";
	static char  buffer[50];
	char *ptr;
	unsigned long int n;
	int sign;

	sign = (num < 0);
	if (sign)
		n = -num;
	else
		n = (unsigned int)num;

	ptr = &buffer[49];
	*ptr = '\0';

	do {
		*--ptr = figurative[n % radix];
		n /= radix;
		/* if (radix == 16 && n == 0)*/
			/* *--ptr = figurative[n]; */
	} while (n);

	if (sign)
		*--ptr = '-';

	return (ptr);
}
