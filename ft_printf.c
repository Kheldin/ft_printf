#include "../libft/libft.h"
#include "includes/libftprintf.h"
#include <stdio.h>

int	get_nb_args(const char *format)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (format[i + 1])
	{
		if (format[i] == '%' && format[i + 1] != '%')
			count++;
		i++;
	}
	return (count);
}

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

int	count_formats(const char *format)
{
	int		count;
	int		i;
	int		flag;

	flag = 0;
	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i - 1] == '%' && is_valid_format(format[i]))
		{
			i++;
			count++;
		}
		i++;
	}
	return (count);
}

char	*get_formats_tab(const char *format)
{
	char	*tab;
	int		i;
	int		j;

	j = 0;
	i = 1;
	tab = ft_calloc(count_formats(format) + 1, sizeof(char));
	if (!tab)
		return (NULL);
	while (format[i])
	{
		if (format[i - 1] == '%' && is_valid_format(format[i]))
			tab[j++] = format[i++];
		else if (format[i - 1] == '%' && !is_valid_format(format[i]))
			return (NULL);
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		nb_args;
	int		i;

	if (!format)
	{
		ft_putstr_fd("Error : type of format != string", 2);
		return (22);
	}
	if (ft_strlen((char *)format) == 1)
		return (ft_putchar_fd(format[0], 1), 0);
	nb_args = get_nb_args(format);
	i = 0;
	va_start(args, format);
	printf("nb format %d qui sont %s", count_formats(format), get_formats_tab(format));
	va_end(args);
	return (0);
}
