/*
** EPITECH PROJECT, 2021
** tests criterion
** File description:
** Tests | Count_elem
*/

#include "../include/my.h"

Test(count_elem, count_element) {
    int i = 0;
    char *str = "?zaer?etrsrfgrth?hedsgt";

    i = count_elem(str, '?');
    cr_assert_eq(i, 3);
}

Test(count_elem, count_element2) {
    int i = 0;
    char *str = "Salut";

    i = count_elem(str, 0);
    cr_assert_eq(i, 5);
}

Test(count_percentage, count_percent) {
    int i = 0;
    char *str = "%ezrgtdf%dzretrd%strgfs";

    i = count_percentage(str);
    cr_assert_eq(i, 3);
}
