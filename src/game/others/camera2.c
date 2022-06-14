/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-alexis.arduca
** File description:
** camera
*/

#include "my.h"

void camera_top_left(all_t *all)
{
    if (all->p->y <= 600 && all->p->x <= 800)
        sfView_setCenter(all->camera, (sfVector2f){800, 600});
    else if (all->p->x <= 800)
        sfView_setCenter(all->camera, (sfVector2f){800, all->p->y});
    else
        camera_player_top(all, 600);
    sfView_setViewport(all->camera, (sfFloatRect){0, 0, 1, 1});
}

void camera_bot_left(all_t *all)
{
    if (all->p->y >= 2304 && all->p->x <= 800)
        sfView_setCenter(all->camera, (sfVector2f){800, 2304});
    else if (all->p->x <= 800)
        sfView_setCenter(all->camera, (sfVector2f){800, all->p->y});
    else
        camera_player_top(all, 2304);
    sfView_setViewport(all->camera, (sfFloatRect){0, 0, 1, 1});
}

void camera_top_right(all_t *all)
{
    if (all->p->y <= 600 && all->p->x >= 3040)
        sfView_setCenter(all->camera, (sfVector2f){3040, 600});
    else if (all->p->x >= 3040)
        sfView_setCenter(all->camera, (sfVector2f){3040, all->p->y});
    else
        camera_player_top(all, 600);
    sfView_setViewport(all->camera, (sfFloatRect){0, 0, 1, 1});
}

void camera_bot_right(all_t *all)
{
    if (all->p->y >= 2304 && all->p->x >= 3040)
        sfView_setCenter(all->camera, (sfVector2f){3040, 2304});
    else if (all->p->x >= 3040)
        sfView_setCenter(all->camera, (sfVector2f){3040, all->p->y});
    else
        camera_player_top(all, 2304);
    sfView_setViewport(all->camera, (sfFloatRect){0, 0, 1, 1});
}
