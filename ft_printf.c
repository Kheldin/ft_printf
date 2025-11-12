#include "includes/ft_printf.h"
#include <stdio.h>

int	is_valid_format(char c)
{
	char	*valid_format;

	valid_format = "cspdiuxX%";
	while (*valid_format)
	{
		if (*valid_format == c)
			return (1);
		valid_format++;
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		counter;

	counter = 0;
	if (!format)
		return (-1);
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && is_valid_format(format[i+1]))
			do_operation(format[++i], args, &counter);
		else if (format[i] != '%')
			ft_putchar_printf(format[i], &counter);
		i++;
	}
	va_end(args);
	return (counter);
}
