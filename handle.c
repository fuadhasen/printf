#include "main.h"

int _printf(const char *format, ...)
{
    va_list args;
    int i = 0;
    va_start(args, format);

    while (format && *format)
    {
        if (*format == '%' && (*(format + 1) == 'd' || *(format + 1) == 'i'))
        {
            format++;
            int num = va_arg(args, int);
            i += print_number(num);
        }
        else
        {
            i += _putchar(*format);
        }

        format++;
    }

    va_end(args);
    return (i);
}
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
