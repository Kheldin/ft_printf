#include "includes/libftprintf.h"

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

	if (!format)
		return (-1);
	if (ft_strlen((char *)format) == 1)
		return (ft_putchar_fd(format[0], 1), 0);
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && is_valid_format(format[i+1]))
			do_operation(format[++i], args);
		else if (format[i] != '%')
			ft_putchar_fd(format[i], 1);
		i++;
	}
	va_end(args);
	return (0);
}
