/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-alexis.arduca
** File description:
** cinematic
*/

#include "my.h"

static void cine_next(all_t *all)
{
    if (all->seconds[0] > 100 && all->seconds[0] < 150) {
        sfRenderWindow_drawSprite(all->window, all->cinematic[2].s->sprite,
        NULL);
        sfRenderWindow_display(all->window);
    }
    if (all->seconds[0] > 150 && all->seconds[0] < 190) {
        sfRenderWindow_drawSprite(all->window, all->cinematic[3].s->sprite,
        NULL);
        sfRenderWindow_display(all->window);
    }
}

void cinematic(all_t *all)
{
    all->time[0] = sfClock_getElapsedTime(all->clock[0]);
    all->seconds[0] = all->time[0].microseconds / 100000.0;
    sfRenderWindow_clear(all->window, sfBlack);
    if (all->seconds[0] > 3 && all->seconds[0] < 40) {
        sfRenderWindow_drawSprite(all->window, all->cinematic[0].s->sprite,
        NULL);
        sfRenderWindow_display(all->window);
    }
    if (all->seconds[0] > 50 && all->seconds[0] < 100) {
        sfRenderWindow_drawSprite(all->window, all->cinematic[1].s->sprite,
        NULL);
        sfRenderWindow_display(all->window);
    }
    if (all->seconds[0] > 190) {
        game(all);
    }
}
