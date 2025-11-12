#include "includes/libftprintf.h"
#include <stdio.h>

int main (void)
{
    int a = 0;

    ft_printf("%c %s %d %i %p %x %X\n", 'Q', "bjr", 1, 2, &a, 78, 78);
    printf("%c %s %d %i %p %x %X\n", 'Q', "bjr", 1, 2, &a, 78, 78);
    ft_printf("%%%%\n"); // Should print 2 % instead of 3
    printf("%%%%\n");
    ft_printf("%p\n", &a);
    printf("%p\n", &a);
    return (0);
}