#include <stdio.h>
#include <limits.h>
#include "main.h"

/**
 * _printf - Prints output based on a format.
 * @format: Format string containing characters and specifiers.
 *
 * Description: This function calls the get_print() function to determine
 * which printing function to use based on
 * the conversion specifiers in the format.
 * Return: Length of formatted output string.
 */

int _printf(const char *format, ...)
{
	int (*pfxn)(va_list, flags_t *);
	const char *p;
	va_list arguments;
	flags_t flags = {0, 0, 0};

	int count = 0;

	va_start(arguments, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = format; *p; p++)
	{
		if (*p == '%')
		{
			p++;
			if (*p == '%')
			{
				count += _putchar('%');
				continue;
			}
			while (get_flag(*p, &flags))
				p++;
			pfxn = get_print(*p);
			count += (pfxn) ? pfxn(arguments, &flags) : _printf("%%%c", *p);
		}
		else
		{
			count += _putchar(*p);
		}
	}
	_putchar(-1);
	va_end(arguments);
	return (count);
}
