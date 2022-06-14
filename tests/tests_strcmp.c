/*
** EPITECH PROJECT, 2021
** Units Tests
** File description:
** Tests | Strcmp
*/

#include "../include/my.h"

Test(my_strcmp, false_compare) {
      int i = 0;
    char str1[6] = "Hello";
    char str2[6] = "Wello";

    i = my_strcmp(str1, str2);
    cr_assert_eq(i, 0);
}

Test(my_strcmp, ratio_compare) {
    int i = 0;
    char str1[7] = "Ratioy";
    char str2[6] = "Ratio";

    i = my_strcmp(str1, str2);
    cr_assert_eq(i, 0);
}

Test(my_strcmp, alpha_compare) {
    int i = 0;
    char str1[7] = "abcdef";
    char str2[7] = "abcdfe";

    i = my_strcmp(str1, str2);
    cr_assert_eq(i, 0);
}

Test(my_strcmp, int_compare) {
    int i = 0;
    char str1[10] = "123456789";
    char str2[10] = "123456789";

    i = my_strcmp(str1, str2);
    cr_assert_eq(i, 1);
}

Test(my_strcmp, ratio_long) {
    int i = 0;
    char str1[28] = "Ratiooooooooooooooooooooooo";
    char str2[28] = "Ratiooooooooooooooooooooooo";

    i = my_strcmp(str1, str2);
    cr_assert_eq(i, 1);
}

Test(my_strcmp, ratio_long_2) {
    int i = 0;
    char str1[28] = "Ratiooooooooooooooooooooooo";
    char str2[28] = "Ratioooooooooooooooooooooo";

    i = my_strcmp(str1, str2);
    cr_assert_eq(i, 0);
}

Test(my_strcmp, ratio_long_3) {
    int i = 0;
    char str1[28] = "Ratioooooooooooooooooooooo";
    char str2[28] = "Ratiooooooooooooooooooooooo";

    i = my_strcmp(str1, str2);
    cr_assert_eq(i, 0);
}
