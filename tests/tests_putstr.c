/*
** EPITECH PROJECT, 2021
** tests criterion
** File description:
** Tests | My_putstr
*/

#include "../include/my.h"

Test(my_putstr, string1, .init = redirect_all_std) {
    my_putstr("Hello");
    cr_assert_stdout_eq_str("Hello");
}

