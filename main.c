#include "includes/libftprintf.h"
#include <stdio.h>

int main (void)
{
    ft_printf("Pas d'args ici\n", 12);
    ft_printf("%dbonjour je %d\n", 12, 45);
    return (0);
}