#include "includes/libftprintf.h"

void	select_operation(char c, char *format_tab, int i)
{
	if (c == 'd')
		ft_putnbr_fd((int)format_tab[i], 1);
	return ;
}