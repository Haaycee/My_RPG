/*
** EPITECH PROJECT, 2021
** tests criterion
** File description:
** Tests | My_put_nbr
*/

#include "../include/my.h"

Test(my_put_nbr, nbr0, .init = redirect_all_std) {
    int i = my_put_nbr(8765);

    cr_assert_stdout_eq_str("8765");
}

Test(my_put_nbr, nbr1, .init = redirect_all_std) {
    int i = my_put_nbr(-2147483648);

    cr_assert_stdout_eq_str("-2147483648");
    cr_assert_eq(i, 0);
}

Test(my_put_nbr, nbr2, .init = redirect_all_std) {
    int i = my_put_nbr(-12);

    cr_assert_stdout_eq_str("-12");
}

Test(my_put_nbr_neg, nbr3, .init = redirect_all_std) {
    int i = my_put_nbr_neg(-643);

    cr_assert_stdout_eq_str("-");
    cr_assert_eq(i, 643);
}

Test(my_put_nbr_neg, nbr4, .init = redirect_all_std) {
    int i = my_put_nbr_neg(-8765);

    cr_assert_stdout_eq_str("-");
    cr_assert_eq(i, 8765);
}
