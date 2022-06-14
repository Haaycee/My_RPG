/*
** EPITECH PROJECT, 2021
** Day06
** File description:
** Lib | Revstr
*/

#include "../../include/my.h"

char *my_revstr(char *str)
{
    int i = my_strlen(str) -1;
    int j;
    int k;
    for (j = 0; j < i; j++) {
        k = str[j];
        str[j] = str[i];
        str[i] = k;
        i = i - 1;
    }
    return (str);
}
