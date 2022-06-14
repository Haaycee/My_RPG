/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-alexis.arduca
** File description:
** pnj_interaction
*/

#include "my.h"

void anim_little_alien(all_t *all)
{
    for (int i = 2; i < 4; i++) {
        all->ennemy[i]->rect.left += 70;
        if (all->ennemy[i]->rect.left >= 140)
            all->ennemy[i]->rect.left = 0;
        sfSprite_setTextureRect(all->ennemy[i]->enemy_s,
        all->ennemy[i]->rect);
    }
}

void boss_spawning(all_t *all)
{
    sfRenderWindow_drawSprite(all->window, all->ennemy[0]->enemy_s, NULL);
    if (all->p->x <= 800 && all->p->y <= 1200)
        all->var[10] = 1;
}

void respawning(int i, all_t *all, ennemy_t *enn)
{
    all->time[5] = sfClock_getElapsedTime(all->clock[5]);
    all->seconds[5] = all->time[5].microseconds / 1000000.0;
    if (all->seconds[5] > 100 && all->ennemy[i]->health == 0) {
        all->ennemy[i]->ennemy_health = 3;
        sfClock_restart(all->clock[5]);
    } else if (all->seconds[5] > 100) {
        sfClock_restart(all->clock[5]);
    }
}

void ennemies_spawning(all_t *all)
{
    all->time[4] = sfClock_getElapsedTime(all->clock[4]);
    all->seconds[4] = all->time[4].microseconds / 1000000.0;
    for (int i = 2; i < 4; i++) {
        respawning(i, all, all->ennemy[i]);
        if (all->ennemy[i]->ennemy_health > 0) {
            detect_adv(all, all->p, all->ennemy[i], i);
            sfRenderWindow_drawSprite(all->window,
            all->ennemy[i]->enemy_s, NULL);
        }
    }
    if (all->seconds[4] > 0.5) {
        anim_little_alien(all);
        sfClock_restart(all->clock[4]);
    }
}
