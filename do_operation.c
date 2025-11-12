#include "includes/ft_printf.h"

void	print_hex_adress(size_t adress, int *counter)
{
	char *hex;

	hex = "0123456789abcdef";
	if (adress > 15)
		print_hex_adress(adress / 16, counter);
	ft_putchar_printf(hex[adress % 16], counter);
}

void	ft_putnbr_printf(long nb, int *counter)
{
	if (nb < 0)
	{
		ft_putchar_printf('-', counter);
		nb *= -1;
	}
	if (nb > 9)
	{
		ft_putnbr_printf(nb / 10, counter);
	}
	ft_putchar_printf((nb % 10) + '0', counter);
}

void	do_operation(char c, va_list args, int *counter)
{
	if (c == 'd' || c == 'i')
		ft_putnbr_printf(va_arg(args, long), counter);
	else if (c == 'u')
		print_unsigned(va_arg(args, unsigned int), counter);
	else if (c == 'c')
		ft_putchar_printf(va_arg(args, int), counter);
	else if (c == 's')
		ft_putstr_printf(va_arg(args, char *), counter);
	else if (c == '%')
		ft_putchar_printf('%', counter);
	else if (c == 'x')
		print_hexl(va_arg(args, long), counter);
	else if (c == 'X')
		print_hexu(va_arg(args, long), counter);
	else if (c == 'p')
	{
		ft_putstr_printf("0x", counter);
		print_hex_adress(va_arg(args, unsigned long), counter);
	}
}
