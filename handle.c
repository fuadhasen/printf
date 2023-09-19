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
