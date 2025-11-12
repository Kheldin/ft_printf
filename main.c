#include "includes/ft_printf.h"
#include <stdio.h>

int main (void)
{
    int a = 0;

    ft_printf("Return value = %d\n", ft_printf("%c %s %d %i %p %x %X oui%%%%\n", 'Q', "bjr", 1, 2, &a, +78, -78));
    printf("Return value = %d\n", printf("%c %s %d %i %p %x %X oui%%%%\n", 'Q', "bjr", 1, 2, &a, 78, -78));
    return (0);
}