#include <stdio.h>
#include <stdarg.h>
#include "main.h"
/**
 * _printf - function to print number of characters printed.
 * @format: char parameter.
 * Authors: Innocent Ingabire and Valodia Uwase
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
                                        {
                                                char arg_c = (char) va_arg(arg_list, int);
                                                        _putchar(arg_c);
                                                char_count++;
                                                break;
                                        }
                                case 's':
                                        {
                                                char *arg_s = va_arg(arg_list, char *);
                                                while (*arg_s)
                                                {
                                                        _putchar(*arg_s++);
                                                        char_count++;
                                                }
                                                break;
                                        }
                                case '%':
                                        {
                                                _putchar('%');
                                                char_count++;
                                                break;
                                        }
                                default:
                                        {
                                                _putchar('%');
                                                _putchar(*format);
                                                char_count += 2;
                                                break;
                                        }
                        }
                }
                else
                {
                        _putchar(*format);
                        char_count++;
                }
                format++;
        }
        va_end(arg_list);
        return (char_count);
}
