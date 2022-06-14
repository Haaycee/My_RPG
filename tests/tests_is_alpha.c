/*
** EPITECH PROJECT, 2021
** Units Tests
** File description:
** Tests | Word Array
*/

#include "../include/my.h"

Test(my_str_is_alpha, is_alpha1) {
    char *str = "ABlkjZAZERFhzbdf";
    int i = my_str_is_alpha(str);

    cr_assert_eq(i, 0);
}

Test(my_str_is_alpha, is_alpha2) {
    char *str = "lk+-!.?jhz1bdf";
    int i = my_str_is_alpha(str);

    cr_assert_eq(i, 1);
}

Test(my_ch_is_alpha, is_alpha3) {
    char ch = 'a';
    int i = my_ch_is_alpha(ch);

    cr_assert_eq(i, 0);
}

Test(my_ch_is_alpha, is_alpha4) {
    char ch = '1';
    int i = my_ch_is_alpha(ch);

    cr_assert_eq(i, 1);
}

Test(verify_is_alpha, is_alpha5) {
    char *str = "ABVa";
    int i = verify_is_alpha(str, 0);

    cr_assert_eq(i, 0);
}

Test(verify_is_alpha, is_alpha9) {
    char *str = "|ABVa";
    int i = verify_is_alpha(str, 0);

    cr_assert_eq(i, 1);
}

Test(my_ch_is_alpha, is_alpha11) {
    char ch = 'A';
    int i = my_ch_is_alpha(ch);

    cr_assert_eq(i, 0);
}

Test(my_ch_is_alpha, is_alpha6) {
    char ch = '|';
    int i = my_ch_is_alpha(ch);

    cr_assert_eq(i, 1);
}

Test(my_ch_is_alpha, is_alpha7) {
    char ch = '[';
    int i = my_ch_is_alpha(ch);

    cr_assert_eq(i, 1);
}

Test(my_ch_is_alpha, is_alpha8) {
    char ch = '.';
    int i = my_ch_is_alpha(ch);

    cr_assert_eq(i, 1);
}
