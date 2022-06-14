/*
** EPITECH PROJECT, 2021
** Day03
** File description:
** Lib | Put_nbr
*/

#include "../../include/my.h"

int my_put_nbr_neg(int nb)
{
    nb = nb * (-1);
    my_putchar('-');
    return (nb);
}

int my_put_nbr(int nb)
{
    if (nb == -2147483648) {
        my_putchar('-');
        my_putchar('2');
        my_put_nbr(147483648);
        return (0);
    }
    if (nb < 0) {
        nb = my_put_nbr_neg(nb);
    }
    if (nb > 9) {
        int v = nb % 10;
        nb = nb / 10;
        my_put_nbr(nb);
        my_putchar(v + 48);
    } else {
        my_putchar(nb + 48);
    }
    return (nb);
}
