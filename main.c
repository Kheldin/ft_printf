#include "includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main (void)
{
    int a = 0;

    ft_printf("%");
    ft_printf("%d\n", ft_printf("%"));
    ft_printf("%f", 3.5);
    ft_printf("\n----------------------------------------\n");
    printf("%");
    printf("%d\n", ft_printf("%"));
    printf("%f", 3.5);

    return (0);
}