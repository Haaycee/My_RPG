/*
** EPITECH PROJECT, 2021
** tests criterion
** File description:
** Tests | My_printf
*/

#include "../include/my.h"

Test(print_arg_d, string2, .init = redirect_all_std) {
    int i = print_arg_d(45);

    cr_assert_stdout_eq_str("45");
    cr_assert_eq(i, 0);
}

Test(print_arg_c, string3, .init = redirect_all_std) {
    int i = print_arg_c('c');

    cr_assert_stdout_eq_str("c");
    cr_assert_eq(i, 0);
}

Test(print_arg_s, string4, .init = redirect_all_std) {
    int i = print_arg_s("%s", "Salut", 0);

    cr_assert_stdout_eq_str("Salut");
    cr_assert_eq(i, 0);
}

Test(print_arg_s, string6) {
    int i = print_arg_s("%d", "Salut", 0);

    cr_assert_eq(i, 0);
}

Test(print_arg_percentage, string5, .init = redirect_all_std) {
    int i = print_arg_percentage();

    cr_assert_stdout_eq_str("%");
    cr_assert_eq(i, 0);
}