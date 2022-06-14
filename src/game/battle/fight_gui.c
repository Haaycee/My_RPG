/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-alexis.arduca
** File description:
** fight_game
*/

#include "my.h"

void menu_attack(all_t *all)
{
    if (all->var[13] == 0)
        all->var[13] = 1;
    else
        all->var[13] = 0;
    all->var[11] = 0;
}

void menu_inv(all_t *all)
{
    return;
}

void leave(all_t *all)
{
    sfView_reset(all->camera, all->cam_rect);
    all->p->x += 100;
    sfSprite_setPosition(all->p->my_player,
    (sfVector2f){all->p->x, all->p->y});
    all->var[10] = 0;
    all->var[11] = 0;
    all->var[12] = 0;
}

void death_reset(all_t *all)
{
    all->p->x = 400;
    all->p->x = 2400;
    all->p->health = 3;
    sfSprite_setPosition(all->p->my_player,
    (sfVector2f){all->p->x, all->p->y});
    sfSprite_setPosition(all->fight->p->my_player,
    (sfVector2f){all->p->x, all->p->y});
    sfRenderWindow_drawSprite(all->window, all->p->my_player, NULL);
    all->var[10] = 0;
    all->fight->turn = 0;
    all->state = MENU;
}
