#include "main.h"

/**
 * _printf - print
 * @format: string
 *
 * Return: i
 */

int _printf(const char *format, ...)
{
	va_list args;
	int i = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
				i += _putchar(va_arg(args, int));
			else if (*format == 's')
			{
				char *str = va_arg(args, char *);

				while (*str)
				{
					i += _putchar(*str);
					str++;
				}
			}
			else if (*format == '%')
			{
				i += _putchar('%');
			}
			else
			{
				i += _putchar('%');
				i += _putchar(*format);
			}
		}
		else
			i += _putchar(*format);
		format++;
	}
	va_end(args);
	return (i);
}




