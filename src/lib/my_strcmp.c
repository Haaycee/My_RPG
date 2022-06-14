/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** Lib | Strcompare
*/

#include "../../include/my.h"

int my_strcmp(char *str, char *env)
{
    int i = 0;

    for (i = 0; str[i] == env[i]; i++) {
        if (str[i + 1] == '\0' && env[i + 1] == '\0')
            return (1);
    }
    return (0);
}
