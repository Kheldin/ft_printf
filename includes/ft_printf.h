#ifndef FT_PRINTF_H
# define FT_PRINTF_H
//#include "../../libft/libft.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

#define ft_printf printf

int	ft_printf(const char *format, ...) __attribute__ ((format (printf, 1, 2)));
void	do_operation(char c, va_list args, int *counter);
int     ft_putchar_printf(char c, int *counter);
void	ft_putstr_printf(char *str, int *counter);
void	ft_putnbr_printf(long nb, int *counter);
void	print_unsigned(unsigned int nb, int *counter);
void	print_hexl(unsigned int nb, int *counter);
void	print_hexu(unsigned int nb, int *counter);
int     ft_strlen_printf(const char *str);


#endif