/*
** EPITECH PROJECT, 2021
** Day06
** File description:
** Lib | Is Alpha
*/

#include "../../include/my.h"

int verify_is_alpha(char *str, int i)
{
    if (str[i] < 65 || str[i] > 90) {
        if (str[i] < 97 || str[i] > 122)
            return (1);
    }
    return (0);
}

int my_str_is_alpha(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (verify_is_alpha(str, i) == 1)
            return (1);
    }
    return (0);
}

int my_ch_is_alpha(char ch)
{
    if (ch < 65 || ch > 90) {
        if (ch < 97 || ch > 122)
            return (1);
    }
    return (0);
}
