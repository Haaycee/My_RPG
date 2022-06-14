/*
** EPITECH PROJECT, 2021
** Day04
** File description:
** Lib | Getnbr
*/

#include "../../include/my.h"

int operator(char const *str)
{
    int result = 0;
    int k = 0;
    int x = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == 45) {
            x = x + 1;
            k = k + 1;
        } else if (str[i] == 43) {
            k = k + 1;
        }
    }
    if (x % 2 != 0)
        my_putchar('-');
    for (k = k; str[k] != '\0' && str[k] >= 48 && str[k] <= 57; k++)
        result = 10 * result + str[k] - 48;
    return (result);
}

int my_getnbr(char const *str)
{
    int result = 0;
    int t = 0;

    if ((str[0] == 43 || str[0] == 45)) {
        result = operator(str);
        t = t + 1;
    }
    if (t == 0) {
        for (int i = 0; str[i] >= 48 && str[i] <= 57; i++) {
            result = 10 * result + str[i] - 48;
        }
    }
    return (result);
}
