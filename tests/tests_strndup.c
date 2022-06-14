/*
** EPITECH PROJECT, 2021
** Units Tests
** File description:
** Tests | Strndup
*/

#include "../include/my.h"

Test(my_strndup, strndup1) {
    char *str = my_strndup("Hello World", 5);

    cr_assert_str_eq("Hello", str);
}

Test(my_strndup, strndup2) {
    char *str = my_strndup("Hello World", 12);

    cr_assert_str_eq("Hello World", str);
}
