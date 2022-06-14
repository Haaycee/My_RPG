/*
** EPITECH PROJECT, 2021
** Units Tests
** File description:
** Tests | is_printable
*/

#include "../include/my.h"

Test(my_str_isprintable, is_print1) {
    char *str = "AZE1234RFlkjhzbdf";
    int i = my_str_isprintable(str);

    cr_assert_eq(i, 0);
}

Test(my_str_isprintable, is_print2) {
    char *str = "lkj/hzbdf";
    int i = my_str_isprintable(str);

    cr_assert_eq(i, 1);
}

Test(my_str_isprintable, is_print3) {
    char *str = "lkjh#zbdf";
    int i = my_str_isprintable(str);

    cr_assert_eq(i, 1);
}

Test(my_str_isprintable, is_print4) {
    char *str = "lkjh:zbdf";
    int i = my_str_isprintable(str);

    cr_assert_eq(i, 1);
}

Test(my_str_isprintable, is_print5) {
    char *str = "[^]";
    int i = my_str_isprintable(str);

    cr_assert_eq(i, 1);
}

Test(my_str_isprintable, is_print6) {
    char *str = "lkjh|zbdf";
    int i = my_str_isprintable(str);

    cr_assert_eq(i, 1);
}

Test(my_str_isprintable, is_print7) {
    char *str = "lkjh`zbdf";
    int i = my_str_isprintable(str);

    cr_assert_eq(i, 1);
}

Test(my_str_isprintable, is_print8) {
    char *str = "lkjh`zbdf";
    int i = my_str_isprintable(str);

    cr_assert_eq(i, 1);
}

Test(my_str_isprintable, is_print9) {
    char *str = "<<>>>";
    int i = my_str_isprintable(str);

    cr_assert_eq(i, 1);
}
