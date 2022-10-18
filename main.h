#ifndef _MAIN_H_
#define _MAIN_H_

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <limits.h>
#include <stdlib.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1

#define FIELD_BUF_SIZE 50

#define NULL_STRING "(null)"

#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/**
 * struct parameters - parameters struct
 *
 * @unsign: flag if unsigned value
 *
 * @plus_flag: on if plus_flag specified
 * @space_flag: on if hashtag_flag specified
 * @hashtag_flag: on if _flag specified
 * @zero_flag: on if _flag specified
 * @minus_flag: on if _flag specified
 *
 * @width: if field width specified
 * @precision: if field precision specified
 *
 * @h_modifier: on if h_modifier is specified
 * @l_modifier: on if l_modifier is specified
 *
 */
typedef struct parameters
{
	unsigned int unsign			: 1;

	unsigned int plus_flag		: 1;
	unsigned int space_flag		: 1;
	unsigned int hashtag_flag	: 1;
	unsigned int zero_flag		: 1;
	unsigned int minus_flag		: 1;

	unsigned int width;
	unsigned int precision;

	unsigned int h_modifier		: 1;
	unsigned int l_modifier		: 1;
} format_t;

/**
 * struct format_op - Typedef strcut
 *
 * @flag: Format
 * @fmt: The intermediate function pointer
 */
typedef struct format_op
{
	char flag;
	int (*fmt)(va_list, format_t *);
} specifier_t;

/* printf.c (main) */
int _printf(const char *format, ...);

/* handlers.c */
int handler(const char *str, va_list args);
int (*handle_specifier(char *str))(va_list arg, format_t *params);
char *handle_precision(char *s, format_t *params, va_list arg);
int get_print_format(char *s, va_list arg, format_t *params);

/* converion specifier (conversion_check.c) */
void init_params(format_t *params, va_list arg);
int handle_modifier(char *s, format_t *params);
char *handle_width(char *s, format_t *params, va_list arg);
int handle_flag(char *s, format_t *params);

/* printers */
int _printfChar(va_list args, format_t *params);
int _printfStr(va_list args, format_t *params);
int _printfInt(va_list arg, format_t *params);
int print_percent(va_list arg, format_t *params);
int _printfBin(va_list args, format_t *params);
int _printf_hex(va_list arg, format_t *params);
int _printf_HEX(va_list arg, format_t *params);
int _printf_octal(va_list arg, format_t *params);
int _printf_unsigned(va_list arg, format_t *params);
int _printf_S(va_list arg, format_t *params);
int _printf_address(va_list arg, format_t *params);
int printf_rot13(va_list arg, format_t *params);
int printf_rev(va_list arg, format_t *params);


/* int operations (print_ints.c) */
int print_number_left_shift(char *str, format_t *params);
int print_number_right_shift(char *str, format_t *params);
int print_number(char *str, format_t *params);

/* _putchar.c */
int _putchar(int c);
int _puts(char *str);

/* string utils */
int print_to(char *start, char *stop, char *except);
int _strlen(char *str);
/* int _strcmp(char *s1, char *s2);*/

/* int_utils.c */
int _isdigit(int c);
char *litoa(long int num, int radix, int flags, format_t *params);

#endif
