#include "main.h"
#include <stdarg.h>

/**
 * handle_d - Handles the %d and %i conversion specifiers.
 * @args: A va_list containing the arguments.
 *
 * Return: The number of characters printed.
 */
int handle_d(va_list args)
{
    int num = va_arg(args, int);
    int count = 0;

    count += print_number(num);

    return (count);
}

/**
 * handle_i - Handles the %i conversion specifier.
 * @args: A va_list containing the arguments.
 *
 * Return: The number of characters printed.
 */
int handle_i(va_list args)
{
    return handle_d(args); // %i is treated the same as %d
}

