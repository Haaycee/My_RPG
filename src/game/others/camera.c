/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-alexis.arduca
** File description:
** camera
*/

#include "my.h"

void camera_player_top(all_t *all, int x)
{
    if (x == 600) {
        if (all->p->y <= x)
            sfView_setCenter(all->camera, (sfVector2f){all->p->x, x});
        else
            sfView_setCenter(all->camera, (sfVector2f){all->p->x, all->p->y});
    } else {
        if (all->p->y >= x)
            sfView_setCenter(all->camera, (sfVector2f){all->p->x, x});
        else
            sfView_setCenter(all->camera, (sfVector2f){all->p->x, all->p->y});
    }
}

void camera_player2(all_t *all)
{
    if (all->p->x >= 1600 && all->p->y < 1350) {
        camera_top_right(all);
    } else if (all->p->x >= 1600 && all->p->y >= 1350) {
        camera_bot_right(all);
    }
}

void camera_player(all_t *all, sfVector2f sprite UNUSED)
{
    if (all->p->x < 1600 && all->p->y < 1350) {
        camera_top_left(all);
    } else if (all->p->x < 1600 && all->p->y >= 1350) {
        camera_bot_left(all);
    } else {
        camera_player2(all);
    }
}
