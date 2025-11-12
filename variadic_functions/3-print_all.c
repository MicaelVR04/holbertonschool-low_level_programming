#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_char - prints a char
 * @ap: argument list
 */
void print_char(va_list ap)
{
	printf("%c", va_arg(ap, int));
}

/**
 * print_int - prints an int
 * @ap: argument list
 */
void print_int(va_list ap)
{
	printf("%d", va_arg(ap, int));
}

/**
 * print_float - prints a float
 * @ap: argument list
 */
void print_float(va_list ap)
{
	printf("%f", va_arg(ap, double));
}

/**
 * print_string - prints a string
 * @ap: argument list
 */
void print_string(va_list ap)
{
	char *s = va_arg(ap, char *);

	if (s == NULL)
		s = "(nil)";
	printf("%s", s);
}

/**
 * print_all - prints anything
 * @format: list of types of arguments passed to the function
 *
 * Return: void
 */
void print_all(const char *const format, ...)
{
	va_list ap;
	unsigned int i = 0, j;
	char *sep = "";

	struct printer
	{
		char t;
		void (*f)(va_list);
	} types[] = {
		{'c', print_char},
		{'i', print_int},
		{'f', print_float},
		{'s', print_string},
		{0, NULL}};

	va_start(ap, format);
	if (format) /* 1st if statement */
	{
		while (format[i])
		{
			j = 0;
			while (types[j].t)
			{
				if (format[i] == types[j].t)
				{
					printf("%s", sep);
					types[j].f(ap);
					sep = ", ";
				}
				j++;
			}
			i++;
		}
	}
	printf("\n");
	va_end(ap);
}
