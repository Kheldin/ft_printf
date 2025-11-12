#include "includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main (void)
{
    int a = 0;

    printf("Return value = %d\n", ft_printf(NULL));
    printf("Return value = %d\n", printf(NULL));
    ft_printf("Return value = %d\n", UINT_MAX);

    return (0);
}