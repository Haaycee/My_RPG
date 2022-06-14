/*
** EPITECH PROJECT, 2021
** tests criterion
** File description:
** Tests | atoi
*/

#include "../include/my.h"

Test(my_atoi, atoi1) {
    int i = 0;
    char str[15] = "42a43";

    i = my_atoi(str);
    cr_assert_eq(i, 42);
}

Test(my_atoi, atoi2) {
    int i = 0;
    char str[15] = "2";

    i = my_atoi(str);
    cr_assert_eq(i, 2);
}
