#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
#include "../../libft/libft.h"
#include <stdarg.h>
#include <stdio.h> // a delete

int	ft_printf(const char *format, ...);
void	do_operation(char c, va_list args);

#endif