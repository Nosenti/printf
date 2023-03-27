#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - printf function
 * @format: format given
 * @...: args
 * Authors: Valodia Uwase and Innocent Ingabire
 * Return: int
 */

int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;

	va_start(args, format);
	for (const char *p = format; *p != '\0'; p++)
	{
		if (*p != '%')
		{
			putchar(*p);
			printed_chars++;
			continue;
		}
		p++;
		switch (*p)
		{
			case 'c':
				char c = va_arg(args, int);

				putchar(c);
				printed_chars++;
				break;
			case 's':
				char *s = va_arg(args, char *);

				for (char *str = s; *str != '\0'; str++)
				{
					putchar(*str);
					printed_chars++;
				}
				break;
			case '%':
				putchar('%');
				printed_chars++;
				break;
			default:
				break;
		}
	}
	va_end(args);
	return (printed_chars);
}
