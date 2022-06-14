/*
** EPITECH PROJECT, 2021
** tests criterion
** File description:
** Tests | My_printf
*/

#include "../include/my.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_printf, simple_string, .init = redirect_all_std)
{
    int i = my_printf("hello world");

    cr_assert_stdout_eq_str("hello world");
    cr_assert_eq(i, 0);
}

Test(my_printf, string2, .init = redirect_all_std) {
    int i = my_printf("Hello %s", "World");

    cr_assert_stdout_eq_str("Hello World");
    cr_assert_eq(i, 0);
}

Test(my_printf, string3, .init = redirect_all_std) {
    int i = my_printf("%d", 112);

    cr_assert_stdout_eq_str("112");
    cr_assert_eq(i, 0);
}

Test(my_printf, string5, .init = redirect_all_std) {
    int i = my_printf("%fSalut", "Yo");

    cr_assert_stdout_eq_str("Salut");
    cr_assert_eq(i, 0);
}

Test(my_printf, string4, .init = redirect_all_std) {
    int i = my_printf("Hello %s, %s and have %d yo.", "World", "Alexis", 19);

    cr_assert_stdout_eq_str("Hello World, Alexis and have 19 yo.");
    cr_assert_eq(i, 0);
}

