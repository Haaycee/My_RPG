/*
** EPITECH PROJECT, 2021
** Units Tests
** File description:
** Tests | My Putchar
*/

#include "../include/my.h"

Test(my_putchar, ch0, .init = redirect_all_std) {
    my_putchar('r');

    cr_assert_stdout_eq_str("r");
}
