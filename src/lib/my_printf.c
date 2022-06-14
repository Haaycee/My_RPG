/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** Lib | printf
*/

#include "../../include/my.h"

int print_arg_d(int stock)
{
    my_put_nbr(stock);
    return (0);
}

int print_arg_c(int stock)
{
    my_putchar(stock);
    return (0);
}

int print_arg_s(char *str, char *stock, int i)
{
    if (str[i + 1] == 's')
        my_putstr(stock);
    return (0);
}

int print_arg_percentage(void)
{
    my_putchar('%');
    return (0);
}

int my_printf(char *str, ...)
{
    va_list list;

    va_start(list, str);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '%' && str[i + 1] == 'd')
            print_arg_d(va_arg(list, int));
        else if (str[i] == '%' && str[i + 1] == 's')
            print_arg_s(str, va_arg(list, char *), i);
        if (str[i] != '%' && str[i - 1] != '%')
            my_putchar(str[i]);
    }
    va_end(list);
    return (0);
}
