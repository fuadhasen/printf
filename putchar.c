#include "main.h"

/**
 * _putchar - print char for future use
 * @c: char
 *
 * Return: c
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
