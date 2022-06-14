/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-alexis.arduca
** File description:
** fight_game
*/

#include "my.h"

static void animation(all_t *all)
{
    all->fight->rect_f.left += 234;
    if (all->fight->rect_f.left >= 934)
        all->fight->rect_f.left = 0;
    sfSprite_setTextureRect(all->fight->fire_s, all->fight->rect_f);
}

void death(all_t *all)
{
    if (all->fight->pos_p.x > all->fight->pos_f.x &&
    all->fight->pos_p.x < all->fight->pos_f.x + 243) {
        if (all->fight->pos_p.y > all->fight->pos_f.y &&
        all->fight->pos_p.y < all->fight->pos_f.y + 103) {
            all->p->health -= 1;
        }
    }
}

void fireball(all_t *all)
{
    animation(all);
    all->fight->pos_f.x -= 50;
    sfSprite_setPosition(all->fight->fire_s, all->fight->pos_f);
    sfClock_restart(all->clock[2]);
}

void enemy_turn(all_t *all)
{
    if (all->fight->pos_f.x <= -100) {
        all->var[17] = 0;
        all->var[14] += 1;
    }
    if (all->var[14] == 5) {
        all->var[14] = 0;
        all->fight->turn = 0;
    }
}

void boss_attack(all_t *all)
{
    all->time[2] = sfClock_getElapsedTime(all->clock[2]);
    all->seconds[2] = all->time[2].microseconds / 1000000.0;
    if (all->var[17] == 0) {
        all->fight->pos_f.x = 1300;
        all->fight->pos_f.y = rand() % 220 + 500;
        all->var[17] = 1;
    }
    if (all->seconds[2] >= 0.04)
        fireball(all);
    sfRenderWindow_drawSprite(all->window, all->fight->fire_s, NULL);
    death(all);
    enemy_turn(all);
}
