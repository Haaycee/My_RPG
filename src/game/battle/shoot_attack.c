/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-alexis.arduca
** File description:
** fight_game
*/

#include "my.h"

void shoot_attack(all_t *all, ennemy_t *enn)
{
    if (all->seconds[3] > 0.08) {
        all->fight->pos_s.x += 80;
        sfSprite_setPosition(all->fight->shoot_s, all->fight->pos_s);
        sfClock_restart(all->clock[3]);
    }
    sfRenderWindow_drawSprite(all->window, all->fight->shoot_s, NULL);
    if (all->fight->pos_s.x > 1400) {
        all->fight->pos_s = (sfVector2f){400, 700};
        all->var[15] = 0;
        enn->ennemy_health -= 1;
        all->fight->turn = 1;
    }
}
