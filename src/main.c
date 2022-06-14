/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-alexis.arduca
** File description:
** main
*/

#include "my.h"

int main(int ac, char **av)
{
    all_t all = {0};

    if (ac > 1 && (my_strcmp(av[1], "--help") || my_strcmp(av[1], "-h"))) {
        my_putstr("USAGE: ./my_rpg\n");
        return 0;
    }
    return (initiate_game(&all, "My_RolePlayGAAAAAAAAAAming", av));
}
