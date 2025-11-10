#include "includes/libftprintf.h"

void	do_operation(char c, va_list args)
{
	if (c == 'd')
		ft_putnbr_fd(va_arg(args, int), 1);
	return ;
}