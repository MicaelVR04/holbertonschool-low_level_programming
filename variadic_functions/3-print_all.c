#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_all - Prints anything.
 * @format: A list of types of arguments passed to the function
 *
 * c: char
 * i: integer
 * f: float
 * s: char * (if the string is NULL, print (nil) instead)
 */
void print_all(const char *const format, ...)
{
	va_list args;
	unsigned int i = 0;
	char *str;
	char *sep = "";

	va_start(args, format);

	while (format && format[i])
	{
		if (format[i] == 'c' || format[i] == 'i' ||
			format[i] == 'f' || format[i] == 's')
		{
			printf("%s", sep);
			sep = ", ";

			switch (format[i])
			{
			case 'c':
				printf("%c", va_arg(args, int));
				break;
			case 'i':
				printf("%d", va_arg(args, int));
				break;
			case 'f':
				printf("%f", va_arg(args, double));
				break;
			case 's':
				str = va_arg(args, char *);
				if (str == NULL)
					str = "(nil)";
				printf("%s", str);
				break;
			}
		}
		i++;
	}

	printf("\n");
	va_end(args);
}
