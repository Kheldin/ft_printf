#include "includes/libftprintf.h"
#include <stdio.h>

int main (void)
{
    int a = 0;

    ft_printf("%c %s %d %i %p %x %X %%%%\n", 'Q', "bjr", 1, 2, &a, 78, 78);
    printf("%c %s %d %i %p %x %X %%%%\n", 'Q', "bjr", 1, 2, &a, 78, 78);
    return (0);
}