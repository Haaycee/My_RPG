/*
** EPITECH PROJECT, 2021
** count_percentage
** File description:
** Lib | Count Element
*/

#include "../../include/my.h"

int count_elem(char *str, char elem)
{
    int j = 0;

    if (!elem)
        return my_strlen(str);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == elem)
            j++;
    }
    return (j);
}

int count_percentage(char *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '%') {
            count += 1;
        }
    }
    return (count);
}
