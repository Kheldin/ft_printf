#include "includes/libftprintf.h"

void	ft_putchar_printf(char c, int *counter)
{
	write(1, &c, 1);
	*counter = *counter + 1;
}

void	ft_putstr_printf(char *str, int *counter)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar_printf(str[i], counter);
		i++;
	}
}

void	print_unsigned(unsigned int nb, int *counter)
{
	if (nb > 9)
		print_unsigned(nb / 10, counter);
	ft_putchar_printf((nb % 10) + '0', counter);
}

void	print_hexl(int nb, int *counter)
{
	char *hex;

	hex = "0123456789abcdef";
	if (nb < 0)
	{
		ft_putchar_printf('-', counter);
		nb *= -1;
	}
	if (nb > 15)
		print_hexl(nb / 16, counter);
	ft_putchar_printf(hex[nb % 16], counter);
}

void	print_hexu(int nb, int *counter)
{
	char *hex;

	hex = "0123456789ABCDEF";
	if (nb < 0)
	{
		ft_putchar_printf('-', counter);
		nb *= -1;
	}
	if (nb > 15)
		print_hexu(nb / 16, counter);
	ft_putchar_printf(hex[nb % 16], counter);
}
