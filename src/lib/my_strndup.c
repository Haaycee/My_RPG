/*
** EPITECH PROJECT, 2021
** B-CPE-110-MPL-1-1-BSQ-hades.cuisinier
** File description:
** my_strndup
*/

#include "my.h"

char *my_strndup(char const *src, int n)
{
    int len_src = my_strlen(src);
    int len = (n > len_src ? len_src : n);
    char *new_str = malloc(sizeof(char) * (len + 1));
    int cpt = 0;

    while (src[cpt] != '\0' && cpt < n) {
        new_str[cpt] = src[cpt];
        cpt++;
    }
    new_str[cpt] = '\0';
    return new_str;
}
