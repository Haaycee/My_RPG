/*
** EPITECH PROJECT, 2021
** Task02
** File description:
** Lib | Strcat
*/

#include "../../include/my.h"

char *my_strcat2(char *dest, char const *src)
{
    char *stock = malloc(sizeof(char) * 64);
    int i = 0;
    int j = 0;

    while (src[i] != '\0') {
        stock[i] = src[i];
        i = i + 1;
    }
    if (stock[i - 1] != '/') {
        stock[i] = '/';
        i++;
    }
    while (dest[j] != '\0') {
        stock[i + j] = dest[j];
        j = j + 1;
    }
    stock[i + j] = '\0';
    return (stock);
}

char *my_strcat(char *dest, char const *src)
{
    char *stock = malloc(sizeof(char *) * 64);
    int i;
    int j;

    for (i = 0; src[i] != '\0'; i++)
        stock[i] = src[i];
    stock[i] = '=';
    i++;
    for (j = 0; dest[j] != '\0'; j++) {
        stock[i + j] = dest[j];
    }
    stock[i + j] = '\0';
    return (stock);
}
