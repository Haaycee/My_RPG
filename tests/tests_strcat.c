/*
** EPITECH PROJECT, 2021
** Units Tests
** File description:
** Tests | Strcat
*/

#include "../include/my.h"

Test(my_strcat, cat1) {
    char *str1 = "oui";
    char *str2 = "non";
    char *str3 = my_strcat(str1, str2);

    cr_assert_str_eq(str3, "non=oui");
}

Test(my_strcat2, cat2) {
    char *str1 = "oui";
    char *str2 = "non";
    char *str3 = my_strcat2(str1, str2);

    cr_assert_str_eq(str3, "non/oui");
}

Test(my_strcat2, cat3) {
    char *str1 = "oui";
    char *str2 = "non/";
    char *str3 = my_strcat2(str1, str2);

    cr_assert_str_eq(str3, "non/oui");
}
