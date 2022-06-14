/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-alexis.arduca
** File description:
** fight_game
*/

#include "my.h"

void slash_anim(all_t *all, ennemy_t *enn)
{
    all->fight->rect_slash.left += 119;
    if (all->fight->rect_slash.left >= 716) {
        enn->ennemy_health -= 2;
        all->fight->rect_slash.left = 0;
        sfSprite_setTextureRect(all->fight->slash_s, all->fight->rect_slash);
        all->fight->pos_p.x = 400;
        sfSprite_setPosition(all->p->my_player, all->fight->pos_p);
        all->fight->turn = 1;
        all->var[15] = 0;
    }
    sfSprite_setTextureRect(all->fight->slash_s, all->fight->rect_slash);
}

void sword_attack(all_t *all, ennemy_t *enn)
{
    if (all->seconds[3] > 0.01 && all->fight->pos_p.x < 1300) {
        all->fight->pos_p.x += 30;
        sfSprite_setPosition(all->p->my_player, all->fight->pos_p);
        sfRenderWindow_drawSprite(all->window, all->p->my_player, NULL);
        sfClock_restart(all->clock[3]);
    }
    if (all->fight->pos_p.x >= 1300) {
        if (all->seconds[3] > 0.08) {
            slash_anim(all, enn);
            sfClock_restart(all->clock[3]);
        }
        sfRenderWindow_drawSprite(all->window, all->fight->slash_s, NULL);
    }
}
