/*
** EPITECH PROJECT, 2021
** Units Tests
** File description:
** Tests | Malloc_2d_array
*/

#include "../include/my.h"

Test(malloc_2d_array, malloc_tab) {
    char **tab = malloc(sizeof(char *) * 64);

    cr_assert(malloc_2d_array(10, 10));
}

Test(free_array, free_tab) {
    char **tab = malloc(sizeof(char) * 8);

    tab = malloc_2d_array(20, 20);
    cr_assert_eq(free_array(tab), 0);
}

Test(free_a_lot_of_function, free_func) {
    char *a = malloc(sizeof(char) * 8);
    char *b = malloc(sizeof(char) * 8);
    char *c = malloc(sizeof(char) * 8);
    char *d = malloc(sizeof(char) * 8);
    char *e = malloc(sizeof(char) * 8);

    cr_assert_eq(free_a_lot_of_function("5", a, b, c, d, e), 0);
}

Test(free_2d_array, free_tab2) {
    char **tab = malloc(sizeof(char) * 8);

    tab = malloc_2d_array(20, 20);
    cr_assert_eq(free_2d_array(tab), 0);
}

Test(my_calloc, my_calloc1) {
    cr_assert_eq(my_calloc(-1), 0);
}
