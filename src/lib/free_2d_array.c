/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-minishell1-hades.cuisinier
** File description:
** free_2d_array
*/

#include <stdlib.h>
#include <stdio.h>

int free_2d_array(char **array)
{
    int i = 0;

    for (i = 0; array[i]; i++)
        free(array[i]);
    free(array);
    return (0);
}
