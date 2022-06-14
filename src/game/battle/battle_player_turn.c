/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-alexis.arduca
** File description:
** fight_game
*/

#include "my.h"

void select_attack_mode(all_t *all)
{
    if (all->pos.x > 220 && all->pos.x < 300) {
        if (all->pos.y > 120 && all->pos.y < 160)
            all->var[15] = 1;
        if (all->pos.y > 223 && all->pos.y < 263)
            all->var[15] = 2;
        if (all->pos.y > 320 && all->pos.y < 360)
            all->var[15] = 3;
    }
    sfClock_restart(all->clock[3]);
}

void player_attack_battle(all_t *all, ennemy_t *enn)
{
    all->time[3] = sfClock_getElapsedTime(all->clock[3]);
    all->seconds[3] = all->time[3].microseconds / 1000000.0;
    sfRenderWindow_drawSprite(all->window, all->fight->menu_atq_s, NULL);
    sfRenderWindow_drawText(all->window, all->fight->atq_sw, NULL);
    sfRenderWindow_drawText(all->window, all->fight->atq_pi, NULL);
    sfRenderWindow_drawText(all->window, all->fight->shield, NULL);
    if (all->event.type == sfEvtMouseButtonPressed && all->seconds[3] >= 0.5)
        select_attack_mode(all);
    if (all->var[15] == 1 && all->fight->turn == 0)
        shoot_attack(all, enn);
    if (all->var[15] == 2 && all->fight->turn == 0)
        sword_attack(all, enn);
    if (all->var[15] == 3 && all->fight->turn == 0)
        shield(all);
}
