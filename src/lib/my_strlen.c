/*
** EPITECH PROJECT, 2021
** Task03
** File description:
** Lib | Strlen
*/

#include "../../include/my.h"

int my_strlen_nbr(char const *str)
{
    int i = 0;
    int k = 0;

    while (str[i] != '\0') {
        if (str[i] >= 48 && str[i] <= 57) {
            k = k + 1;
        }
        i = i + 1;
    }
    return (k);
}

int my_strlen(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        i = i + 1;
    }
    return (i);
}

int strrlen(char **env)
{
    int i = 0;

    while (env[i] != NULL)
        i++;
    return (i);
}
