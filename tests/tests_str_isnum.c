/*
** EPITECH PROJECT, 2021
** Units Tests
** File description:
** Tests | Word Array
*/

#include "../include/my.h"

Test(my_str_isnum, isnum0) {
    char *str = "lkjhzbdf";
    int i = my_str_isnum(str);

    cr_assert_eq(i, 0);
}

Test(my_str_isnum, isnum1) {
    char *str = "+-*";
    int i = my_str_isnum(str);

    cr_assert_eq(i, 0);
}

Test(my_str_isnum, isnum2) {
    char *str = "12345";
    int i = my_str_isnum(str);

    cr_assert_eq(i, 1);
}
