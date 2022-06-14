/*
** EPITECH PROJECT, 2021
** B-BOO-101-MPL-1-1-phoenixd01-hades.cuisinier
** File description:
** reverse_string
*/

#include "my.h"

char *my_revstr2(char *str)
{
    int length = my_strlen(str) -1;
    int counter = 0;
    char temp = 'a';

    while (length > counter) {
        temp = str[counter];
        str[counter] = str[length];
        str[length] = temp;
        length--;
        counter++;
    }
    return (str);
}
