/*
** EPITECH PROJECT, 2021
** Units Tests
** File description:
** Tests | Word_array
*/

#include "../include/my.h"

Test(my_word_array, word_array) {
    int i = 0;
    char *str = "Hello World Ratio à toi Tibo";
    char **tab = my_word_array(str, ' ');

    cr_assert_str_eq(tab[0], "Hello");
    cr_assert_str_eq(tab[1], "World");
    cr_assert_str_eq(tab[2], "Ratio");
    cr_assert_str_eq(tab[3], "à");
    cr_assert_str_eq(tab[4], "toi");
    cr_assert_str_eq(tab[5], "Tibo");
}

Test(my_word_array, word_array2) {
    int i = 0;
    char *str = "   ";
    char **tab = my_word_array(str, ',');

    cr_assert_str_eq(tab[0], "   ");
}

Test(my_word_array, word_array3) {
    int i = 0;
    char *str = "Hello12345+-=*.?";
    char **tab = my_word_array(str, 'p');

    cr_assert_str_eq(tab[0], "Hello12345+-=*.?");
}
