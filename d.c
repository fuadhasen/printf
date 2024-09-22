#include "main.h"

/**
 * _p - Custom printf function for custome use
 * @format: The format string.
 *
 * Return: The number of characters printed.
 */
int _p(const char *format, ...)
{
	va_list args;
	int i = 0;

	va_start(args, format);

	while (format && *format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'd' || *format == 'i')
			{
				int num = va_arg(args, int);

				i += print_number(num);
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

