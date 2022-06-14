/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-alexis.arduca
** File description:
** fight_game
*/

#include "my.h"

void shield_anim(all_t *all)
{
    all->fight->rect_slash.left += 119;
    if (all->fight->rect_slash.left >= 716) {
        all->fight->rect_slash.left = 0;
        all->fight->pos_p.x = 400;
        sfSprite_setPosition(all->p->my_player, all->fight->pos_p);
        all->var[15] = 0;
    }
    sfSprite_setTextureRect(all->fight->slash_s, all->fight->rect_slash);
}

void shield(all_t *all)
{
    return;
}
