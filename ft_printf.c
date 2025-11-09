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

int	count_formats(const char *format)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (format[i + 1])
	{
		if (format[i] == '%')
			count++;	
		i++;
	}
	return (count);
}

char	*formats_tab(const char *format)
{
	char	*tab;
	int		i;
	int		j;

	j = 0;
	i = 0;
	tab = ft_calloc(count_formats(format) + 1, sizeof(char));
	if (!tab)
		return (NULL);
	while (format[i + 1])
	{
		if (format[i] == '%')
			tab[j++] = format[i + 1];
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
	nb_args = get_nb_args(format);
	i = 0;
	va_start(args, format);
	printf("nb format %d qui sont du type %s", count_formats(format), formats_tab(format));
	va_end(args);
	return (0);
}
