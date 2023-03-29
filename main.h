#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "0-putchar.c"

int _putchar(char c);
int _printf(const char *format, ...);
int _position(const char *s, int n);
int _strlen(char *s);
int _abs(int n);
int _numlen(int n);
char *_strcat(char *dest, char *src, int n);
void *rev_string(char *s);
#endif /* MAIN_H */
