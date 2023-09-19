#include "main.h"
#include <unistd.h>

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

/**
 * print_number - Custom function to print an integer.
 * @n: The integer to be printed.
 *
 * Return: The number of characters printed.
 */
int print_number(int n)
{
	int count = 0;
	unsigned int num;

	if (n < 0)
	{
		write(1, "-", 1);
		num = -n;
		count++;
	}
	else
	{
		num = n;
	}
	if (num / 10 != 0)
	{
		count += print_number(num / 10);
	}
	_putchar('0' + (num % 10));
	count++;

	return (count);
}

