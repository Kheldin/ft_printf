#include <stdio.h>
#include <limits.h>
#include "includes/ft_printf.h"

int main(void)
{
    int r1, r2;

    printf("\n=== STRING ===\n");
    r1 = printf("printf : %s\n", "hello");
    r2 = ft_printf("ft_printf : %s\n", "hello");
    printf("retours -> printf: %d | ft_printf: %d\n\n", r1, r2);

    printf("\n=== CHAR ===\n");
    r1 = printf("printf : %c %c %c\n", 'a', 'Z', 0);
    r2 = ft_printf("ft_printf : %c %c %c\n", 'a', 'Z', 0);
    printf("retours -> printf: %d | ft_printf: %d\n\n", r1, r2);

    printf("\n=== INT (d/i) ===\n");
    r1 = printf("printf : %d | %i | %d | %i\n", 0, -1, INT_MAX, INT_MIN);
    r2 = ft_printf("ft_printf : %d | %i | %d | %i\n", 0, -1, INT_MAX, INT_MIN);
    printf("retours -> printf: %d | ft_printf: %d\n\n", r1, r2);

    printf("\n=== UNSIGNED (u) ===\n");
    r1 = printf("printf : %u | %u\n", 0, UINT_MAX);
    r2 = ft_printf("ft_printf : %u | %u\n", 0, UINT_MAX);
    printf("retours -> printf: %d | ft_printf: %d\n\n", r1, r2);

    printf("\n=== HEXA (x/X) ===\n");
    r1 = printf("printf : %x | %X | %x\n", 0, 255, UINT_MAX);
    r2 = ft_printf("ft_printf : %x | %X | %x\n", 0, 255, UINT_MAX);
    printf("retours -> printf: %d | ft_printf: %d\n\n", r1, r2);

    printf("\n=== POINTER (p) ===\n");
    int a = 42;
    r1 = printf("printf : %p | %p\n", &a, NULL);
    r2 = ft_printf("ft_printf : %p | %p\n", &a, NULL);
    printf("retours -> printf: %d | ft_printf: %d\n\n", r1, r2);

    printf("\n=== PERCENT (%%) ===\n");
    r1 = printf("printf : %% %% %%\n");
    r2 = ft_printf("ft_printf : %% %% %%\n");
    printf("retours -> printf: %d | ft_printf: %d\n\n", r1, r2);

    printf("\n=== COMBO ===\n");
    r1 = printf("printf : char=%c | str=%s | int=%d | hex=%x | ptr=%p | %%\n",
                'A', "test", -12345, 3735928559u, &a);
    r2 = ft_printf("ft_printf : char=%c | str=%s | int=%d | hex=%x | ptr=%p | %%\n",
                'A', "test", -12345, 3735928559u, &a);
    printf("retours -> printf: %d | ft_printf: %d\n\n", r1, r2);

    return 0;
}
