/*
** EPITECH PROJECT, 2021
** count_percentage
** File description:
** Lib | Malloc 2d array
*/

#include "../../include/my.h"

char **my_word_array(char *str, char sep)
{
    int x = 0;
    int k = 0;
    int i = 0;
    char **tab = malloc_2d_array(count_elem(str, sep) + 1, 4);

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == sep) {
            tab[x][k + 1] = '\0';
            k = 0;
            x += 1;
        } else {
            tab[x][k] = str[i];
            k += 1;
        }
    }
    tab[x][k] = str[i];
    tab[x][k + 1] = '\0';
    return (tab);
}
