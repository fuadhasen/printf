#include "main.h"

/**
 * print_number - Custom function to print an integer
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
	_putchar((char)('0' + (num % 10)));
	count++;
	return (count);
}
