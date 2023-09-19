#include "main.h"

/**
 * _p - Custom printf function
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
			if (*format == '\0')
				break;
			if (*format == 'd' || *format == 'i')
			{
				int num = va_arg(args, int);

				i += print_number(num);
			}
			format++;
		}
		else
		{
			i += write(1, format, 1);
			format++;
		}
	}
	va_end(args);
	return (i);
}

