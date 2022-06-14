/*
** EPITECH PROJECT, 2021
** Day06
** File description:
** Task16
*/

#include "../../include/my.h"

int my_str_isprintable(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] <= 45 || str[i] >= 123)
            return (1);
        if (str[i] == '/')
            return (1);
        if (str[i] >= 58 && str[i] <= 64)
            return (1);
        if (str[i] >= 91 && str[i] <= 94)
            return (1);
        if (str[i] == 96)
            return (1);
    }
    return (0);
}
