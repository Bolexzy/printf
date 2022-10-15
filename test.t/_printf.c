#include "main.h"

/**/
int _printf(const char *format, ...)
{
	int i;
	va_list arg;
	char  *str;
	const char *cross;

	va_start(arg, format);
	for (cross = format; *cross != '\0'; cross++)
	{
		while (*cross != '%')
		{
			 if( *cross == '\0') 
				 return (0);
			_putchar(*cross);
			cross++;
		}

		cross++;

		/**/
		switch (*cross)
		{
			case 'c':
				i = va_arg(arg, int);
				_putchar(i);
				break;
			case 's':
				str = va_arg(arg, char *);
				_puts(str);
				break;
			case 'i':
			case 'd':
				i = va_arg(arg, int);
				if (i < 0)
				{
					_putchar(45);
					i *= -1;
				}
				_puts(convert(i, 10));
				break;
			default:
				cross++;
				continue;
		}
	}
	va_end(arg);
	return (0);
}
