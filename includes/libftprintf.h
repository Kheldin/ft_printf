#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
#include "../../libft/libft.h"
#include <stdarg.h>

int	ft_printf(const char *format, ...);
void	select_operation(char c, char *format_tab, int i);

#endif