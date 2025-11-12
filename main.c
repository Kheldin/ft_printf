#include "includes/libftprintf.h"
#include <stdio.h>

int main (void)
{
    int a = 0;

    ft_printf("Pas d'args ici\n", 12);
    ft_printf("%ubonjour je %d\n", -12, 45);
    ft_printf("%s carac : %c\n", "Je suis une str", 'z');
    ft_printf("%x\n", 39);
    ft_printf("%x\n", 16);
    ft_printf("%x\n", 32);
    ft_printf("%x\n", 0);
    printf("%x\n", 39);
    printf("%x\n", 16);
    printf("%x\n", 32);
    printf("%x\n", 0);
    ft_printf("%%%%\n"); // Should print 2 % instead of 3
    printf("%%%%\n");
    ft_printf("%p\n", &a);
    printf("%p\n", &a);
    return (0);
}