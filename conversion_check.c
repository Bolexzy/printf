#include "main.h"

/**
 * init_params - clears struct fields and reset buf
 *
 * @params: the parameters struct
 * @arg: the argument pointer
 * Return: void
 */

void init_params(format_t *params, va_list arg)
{
	params->unsign = 0;

	params->plus_flag = 0;
	params->space_flag = 0;
	params->hashtag_flag = 0;
	params->zero_flag = 0;
	params->minus_flag = 0;

	params->width = 0;
	params->precision = UINT_MAX;

	params->h_modifier = 0;
	params->l_modifier = 0;
	(void)arg;
}

/**
 * handle_flag - finds the flag functions
 *
 * @s: the format string
 * @params: the parameters struct
 * Return: if flag was valid
 */

int handle_flag(char *s, format_t *params)

{
	int i = 0;

	switch (*s)
	{
		case '+':
			i = params->plus_flag = 1;
			break;
		case ' ':
			i = params->space_flag = 1;
			break;
		case '#':
			i = params->hashtag_flag = 1;
			break;
		case '-':
			i = params->minus_flag = 1;
			break;
		case '0':
			i = params->zero_flag = 1;
			break;
	}
	return (i);
}

/**
 * handle_modifier - checks the modifier function
 *
 * @s: string for format
 * @params: parameter structure
 * Return: modifier, if valid.
 */

int handle_modifier(char *s, format_t *params)
{
	int i = 0;

	switch (*s)
	{
		case 'h':
			i = params->h_modifier = 1;
			break;
		case 'l':
			i = params->l_modifier = 1;
			break;
	}
	return (i);
}

/**
 * handle_width - gets the width from the format string
 *
 * @s: the format string
 * @params: the parameters struct
 * @arg: the argument pointer
 * Return: new pointer
 */

char *handle_width(char *s, format_t *params, va_list arg)

	/* should this function use char **s and modify the pointer? */
{
	int d = 0;

	if (*s == '*')
	{
		d = va_arg(arg, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			d = d * 10 + (*s++ - '0');
	}
	params->width = d;
	return (s);
}
