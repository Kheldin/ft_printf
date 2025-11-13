#include "includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main (void)
{
    int a = 0;

    // ft_printf("%");
    // ft_printf("%d\n", ft_printf("%"));
    // ft_printf("%f", 3.5);
    // ft_printf("\n----------------------------------------\n");
    // printf("%");
    // printf("%d\n", ft_printf("%"));
    // printf("%f", 3.5);

    ft_printf("return value : %d", ft_printf("Bonjour jai %d ans %s\n", 20, "oim"));
    printf("return value %d", printf("Bonjour jai %d ans %s\n", 20, "oim"));

    return (0);
}