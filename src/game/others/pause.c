/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-alexis.arduca
** File description:
** pause
*/

#include "my.h"

void pause_position(all_t *all)
{
    sfRenderWindow_setView(all->window, all->camera);
    sfSprite_setPosition(all->pause_s[0].s->sprite,
    sfRenderWindow_mapPixelToCoords(all->window,
    (sfVector2i){780, 230}, all->camera));
    sfSprite_setPosition(all->pause_s[1].s->sprite,
    sfRenderWindow_mapPixelToCoords(all->window,
    (sfVector2i){780, 420}, all->camera));
    sfSprite_setPosition(all->pause_s[2].s->sprite,
    sfRenderWindow_mapPixelToCoords(all->window,
    (sfVector2i){780, 610}, all->camera));
    sfSprite_setPosition(all->pause_s[3].s->sprite,
    sfRenderWindow_mapPixelToCoords(all->window,
    (sfVector2i){550, 700}, all->camera));
    sfSprite_setPosition(all->pause_s[4].s->sprite,
    sfRenderWindow_mapPixelToCoords(all->window,
    (sfVector2i){1050, 700}, all->camera));
}

void pause_draw(all_t *all)
{
    for (int i = 0; i < 3; i++) {
        sfRenderWindow_drawSprite(all->window,
        all->pause_s[i].s->sprite, NULL);
    }
    if (all->pause_s[2].is_clicked) {
        sfRenderWindow_drawSprite(all->window,
        all->pause_s[3].s->sprite, NULL);
        sfRenderWindow_drawSprite(all->window,
        all->pause_s[4].s->sprite, NULL);
    }
}
