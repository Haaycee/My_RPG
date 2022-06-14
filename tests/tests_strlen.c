/*
** EPITECH PROJECT, 2021
** Units Tests
** File description:
** Tests | Strlen
*/

#include "../include/my.h"

Test(my_strlen, strlen1) {
    int i = 0;
    char str[12] = "Hello World";

    i = my_strlen(str);
    cr_assert_eq(i, 11);
}

Test(my_strlen, strlen2) {
    int i = 0;
    char *str = "";

    i = my_strlen(str);
    cr_assert_eq(i, 0);
}

Test(my_strlen_nbr, strlen_nbr) {
    int i = 0;
    char *str = "zbAZER#!k43kh7l9";

    i = my_strlen_nbr(str);
    cr_assert_eq(i, 4);
}

Test(strrlen, strrlen) {
    int i = 0;
    char *tab[2];

    tab[0] = "salut";
    tab[1] = "salut";
    tab[2] = NULL;

    i = strrlen(tab);
    cr_assert_eq(i, 2);
}

Test(len_2d_array, strrlen2) {
    int i = 0;
    char *tab[2];

    tab[0] = "salut";
    tab[1] = "salut";
    tab[2] = NULL;

    i = len_2d_array(tab);
    cr_assert_eq(i, 2);
}
