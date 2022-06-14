/*
** EPITECH PROJECT, 2021
** tests criterion
** File description:
** Tests | getnbr
*/

#include "../include/my.h"

Test(my_getnbr, alpha_separator) {
    int i = 0;
    char str[15] = "42a43";

    i = my_getnbr(str);
    cr_assert_eq(i, 42);
}

Test(my_getnbr, negative_value, .init = redirect_all_std) {
    int i = 0;
    char str[25] = "+---+--++---+---+---+-42";

    i = my_getnbr(str);
    cr_assert_stdout_eq_str("-");
    cr_assert_eq(i, 42);
}

Test(my_getnbr, negative_value2, .init = redirect_all_std) {
    int i = 0;
    char *str = "-42";

    i = my_getnbr(str);
    cr_assert_stdout_eq_str("-");
    cr_assert_eq(i, 42);
}

Test(my_getnbr, positive_value) {
    int i = 0;
    char *str = "+42.";

    i = my_getnbr(str);
    cr_assert_eq(i, 42);
}

Test(my_getnbr, classic_number) {
    int i = 0;
    char str[8] = "4368934";

    i = my_getnbr(str);
    cr_assert_eq(i, 4368934);
}

Test(operator, negative, .init = redirect_all_std) {
    int i = 0;
    char *str = "-18";

    i = operator(str);
    cr_assert_stdout_eq_str("-");
    cr_assert_eq(i, 18);
}

Test(operator, positive, .init = redirect_all_std) {
    int i = 0;
    char *str = "+18";

    i = operator(str);
    cr_assert_eq(i, 18);
}

Test(operator, only_op, .init = redirect_all_std) {
    int i = 0;
    char *str = "+++-+++-----+-";

    i = operator(str);
    cr_assert_eq(i, 0);
}

Test(operator, ch, .init = redirect_all_std) {
    int i = 0;
    char *str = "bdfgbfa";

    i = operator(str);
    cr_assert_eq(i, 0);
}

Test(operator, ch2, .init = redirect_all_std) {
    int i = 0;
    char *str = ".";

    i = operator(str);
    cr_assert_eq(i, 0);
}
