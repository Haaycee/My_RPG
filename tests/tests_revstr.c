/*
** EPITECH PROJECT, 2021
** Units Tests
** File description:
** Tests | Count Revstr
*/

#include "../include/my.h"

Test(my_revstr, copy_five_characters_in_empty_array) {
    char str[6] = "hello";

    my_revstr(str);
    cr_assert_str_eq(str, "olleh");
}
