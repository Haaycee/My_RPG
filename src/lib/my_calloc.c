/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-alexis.arduca
** File description:
** my_calloc
*/

#include "../../include/my.h"

void *my_calloc(unsigned long size)
{
    void *ptr = malloc(size);

    if (!ptr)
        return 0;
    for (int i = 0; i < size; i++)
        ((char *)ptr)[i] = 0;
    return (ptr);
}
