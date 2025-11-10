#include "includes/libftprintf.h"

static void	print_unsigned(unsigned int nb)
{
	if (nb > 9)
		print_unsigned(nb / 10);
	ft_putchar_fd((nb % 10) + '0', 1);
}

static void	print_hexl(int nb)
{
	char *hex;

	hex = "0123456789abcdef";
	if (nb < 0)
	{
		ft_putchar_fd('-', 1);
		nb *= -1;
	}
	if (nb > 15)
		print_hexl(nb / 16);
	ft_putchar_fd(hex[nb % 16], 1);
}

static void	print_hexu(int nb)
{
	char *hex;

	hex = "0123456789ABCDEF";
	if (nb < 0)
	{
		ft_putchar_fd('-', 1);
		nb *= -1;
	}
	if (nb > 15)
		print_hexl(nb / 16);
	ft_putchar_fd(hex[nb % 16], 1);
}

void	do_operation(char c, va_list args)
{
	if (c == 'd' || c == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (c == 'u')
		print_unsigned(va_arg(args, unsigned int));
	else if (c == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	else if (c == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	else if (c == '%')
		ft_putchar_fd('%', 1);
	else if (c == 'x')
		print_hexl(va_arg(args, int));
	else if (c == 'X')
		print_hexu(va_arg(args, int));
	return ;
}
