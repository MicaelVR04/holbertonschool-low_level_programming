#include "lists.h"

/**
 * print_uint - prints an unsigned int using _putchar
 * @n: number to print
 */
static void print_uint(unsigned int n)
{
	if (n / 10)
		print_uint(n / 10);
	_putchar((n % 10) + '0');
}

/**
 * print_cstr - prints a C string using _putchar
 * @s: string to print (assumed non-NULL)
 */
static void print_cstr(const char *s)
{
	while (*s)
	{
		_putchar(*s);
		s++;
	}
}

/**
 * print_list - prints all elements of a list_t list
 * @h: pointer to the head of the list
 *
 * Return: number of nodes
 */
size_t print_list(const list_t *h)
{
	size_t count = 0;

	while (h)
	{
		_putchar('[');
		print_uint(h->len);
		_putchar(']');
		_putchar(' ');
		if (h->str)
			print_cstr(h->str);
		else
			print_cstr("(nil)");
		_putchar('\n');

		h = h->next;
		count++;
	}
	return (count);
}
