#ifndef _MAIN_H_
#define _MAIN_H_

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

/**
 * struct format_op - Typedef strcut
 *
 * @flag: Format
 * @fmt: The intermediate function pointer
 */
typedef struct format_op
{
	char flag;
	int (*fmt)(va_list);
} format;

/* printf.c (main) */
int _printf(const char *format, ...);

/* handler.c */
int handler(const char *str, va_list args);
int specifier_handler(const char *str, va_list arg, int *index);

/* printers */
int _printfChar(va_list args);
int _printfStr(va_list args);
int _printfInt(va_list args);
int _printfBin(va_list args);
int _printfUnsigned(va_list args);
int _printfOct(va_list args);
int _printfHex_Cap(va_list args);
int _printfHex_Low(va_list args);

/* _putchar.c */
int _putchar(char c);
int buffer(char c);

/* string utils */
char *litoa(long int num, int radix);
int print(char *str);
int _strlen(const char *str);
char *str_tolower(char *s);

#endif
