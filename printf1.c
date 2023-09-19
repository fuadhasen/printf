#include "main.h"
#include <unistd.h>

/**
 * _printf - Custom printf function
 * @format: The format string.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
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
            i += _putchar(*format);
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
        _putchar('-');
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

/**
 * _putchar - Custom function to print a character to stdout.
 * @c: The character to be printed.
 *
 * Return: 1 (Success), -1 (Failure).
 */
int _putchar(char c)
{
    return write(1, &c, 1);
}

