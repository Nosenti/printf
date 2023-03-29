#include <stdio.h>
#include <stdarg.h>
#include "main.h"
int handle_char(va_list arg_list);
int handle_string(va_list arg_list);
int handle_percent(void);
/**
 * _printf - function to print number of characters
 * @format: char parameter
 * Return: character.
 */
int _printf(const char *format, ...)
{
	int char_count;
	va_list arg_list;

	char_count = 0;
	va_start(arg_list, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					char_count += handle_char(arg_list);
					break;
				case 's':
					char_count += handle_string(arg_list);
					break;
				case '%':
					char_count += handle_percent();
					break;
				default:
					putchar('%');
					putchar(*format);
					char_count += 2;
					break;
			}
		}
		else
		{
			putchar(*format);
			char_count++;
		}
		format++;
	}
	va_end(arg_list);
	return (char_count);
}
/**
 * handle_char - function that handles character arguments.
 * @arg_list: list of arguments
 * Return: 1.
 */
int handle_char(va_list arg_list)
{
	char arg_c = (char) va_arg(arg_list, int);

	putchar(arg_c);
	return (1);
}
/**
 * handle_string - function to handle arguments.
 * @arg_list: list of arguments
 * Return: a number
 */
int handle_string(va_list arg_list)
{
	int count = 0;
	char *arg_s = va_arg(arg_list, char *);

	while (*arg_s)
	{
		putchar(*arg_s++);
		count++;
	}
	return (count);
}
/**
 * handle_percent - function that returns a character.
 * Return: 1
 */
int handle_percent(void)
{
	putchar('%');
	return (1);
}
