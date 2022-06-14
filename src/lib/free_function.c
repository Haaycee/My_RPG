/*
** EPITECH PROJECT, 2021
** count_percentage
** File description:
** Lib | Free array
*/

#include "../../include/my.h"

int free_a_lot_of_function(char *nb, ...)
{
    va_list list;

    va_start(list, nb);
    for (int i = 0; i < my_getnbr(nb); i++) {
        free(va_arg(list, char *));
    }
    va_end(list);
    return (0);
}

int free_array(char **tab)
{
    free(tab);
    return (0);
}
