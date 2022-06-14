/*
** EPITECH PROJECT, 2021
** count_percentage
** File description:
** Lib | Malloc 2d array
*/

#include "my.h"

char **malloc_2d_array(unsigned long nb_rows, unsigned long nb_cols)
{
    int i = 0;
    char **res;

    res = my_calloc(sizeof(char *) * (nb_rows + 1));
    for (i = 0; i < nb_rows; i++)
        res[i] = my_calloc(sizeof(char) * nb_cols + 1);
    return (res);
}
