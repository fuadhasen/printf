#include "main.h"

/**
 * _printf - printf
 * @format: foramt specifier
 *
 * Return: i
 */

int _printf(const char *format, ...)
{
	va_list arg;
	int i = 0;
	char *s;

	va_start(arg, format);


	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'd' || *format == 'i')
			{
				int v = va_arg(arg, int);
				char str[20];
				snprintf(str, sizeof(str), "%d", v);
				s = str;
				while (*s)
				{
					i += _putchar(*s);
					s++;
				}
			}
			else
			{
				i += _putchar('%');
				i += _putchar(*format);
			}
		}
		else
		{
			i += _putchar(*format);
		}
		format++;
	}
	va_end(arg);
	return (i);
}

