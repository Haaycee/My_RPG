/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-alexis.arduca
** File description:
** init_game
*/

#include "my.h"

int initiate_game(all_t *all, char *name, char **av)
{
    char *path = "./src/assets/maps/map_col.txt";
    all = init_struct(name);
    if (!all)
        return 84;
    if (av[1] && my_strcmp(av[1], "--hunter"))
        all->state = HUNTER;
    generate_colissions(path, all);
    game_loop(all);
    destroy_all(all);
    return 0;
}
