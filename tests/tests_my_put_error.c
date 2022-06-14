/*
** EPITECH PROJECT, 2021
** tests criterion
** File description:
** Tests | My_put_error
*/

#include "../include/my.h"

Test(my_putstr_error, string2, .init = redirect_all_std) {
    int i = my_putstr_error("Salut le Bug");

    cr_assert_eq(i, 0);
}
