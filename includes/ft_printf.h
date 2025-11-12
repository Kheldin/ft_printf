#ifndef FT_PRINTF_H
# define FT_PRINTF_H
//#include "../../libft/libft.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h> // a delete

int	ft_printf(const char *format, ...);
void	do_operation(char c, va_list args, int *counter);
void	ft_putchar_printf(char c, int *counter);
void	ft_putstr_printf(char *str, int *counter);
void	ft_putnbr_printf(long nb, int *counter);
void	print_unsigned(unsigned int nb, int *counter);
void	print_hexl(long nb, int *counter);
void	print_hexu(long nb, int *counter);


#endif