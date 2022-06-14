/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-minishell1-hades.cuisinier
** File description:
** len_2d_array
*/

int len_2d_array(char **array)
{
    int i = 0;

    while (array[i])
        i++;
    return i;
}
