/*
** EPITECH PROJECT, 2021
** Day06
** File description:
** Lib | Is Number
*/

#include "../../include/my.h"

int my_str_isnum(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 48 || str[i] > 57) {
            return (0);
        }
    }
    return (1);
}
