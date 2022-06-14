/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-alexis.arduca
** File description:
** dialogues.c
*/

#include "my.h"

static void math_conditional(all_t *all)
{
    if (all->statue_t >= 1) {
        sfSprite_setPosition(all->dialogue_s[2].s->sprite, \
        sfRenderWindow_mapPixelToCoords(all->window, \
        (sfVector2i){830 + (0 * 200), 780}, all->camera));
        sfRenderWindow_drawSprite(all->window,
        all->dialogue_s[2].s->sprite, NULL);
    } else {
        sfSprite_setPosition(all->dialogue_s[1].s->sprite, \
        sfRenderWindow_mapPixelToCoords(all->window, \
        (sfVector2i){830 + (0 * 200), 780}, all->camera));
        sfRenderWindow_drawSprite(all->window,
        all->dialogue_s[1].s->sprite, NULL);
    }
    if (all->statue_s >= 1) {
        sfSprite_setPosition(all->quest[0].s->sprite, \
        sfRenderWindow_mapPixelToCoords(all->window, \
        (sfVector2i){0 + (0 * 100), 0}, all->camera));
        sfRenderWindow_drawSprite(all->window, all->quest[0].s->sprite, NULL);

    }
}

static void math_log(all_t *all)
{
    sfVector2f png_tmp = {2480, 2310};
    sfVector2f player_t = sfSprite_getPosition(all->p->my_player);
    sfVector2i player = {(int) player_t.x, (int) player_t.y};

    if (all->statue_s != 0 && is_on(player, png_tmp, 40, 30)
    && all->event.key.code == sfKeyB) {
        all->statue_t++;
        sfSprite_setPosition(all->quest[1].s->sprite, \
        sfRenderWindow_mapPixelToCoords(all->window, \
        (sfVector2i){0 + (0 * 100), 0}, all->camera));
        sfRenderWindow_drawSprite(all->window,
        all->quest[1].s->sprite, NULL);
        sfSprite_setPosition(all->dialogue_s[0].s->sprite,
        (sfVector2f){2810, 2470});
        sfRenderWindow_drawSprite(all->window,
        all->dialogue_s[1].s->sprite, NULL);
    }
}

void dialogue_mathematician(all_t *all)
{
    sfVector2f png = {2810, 2480};
    sfVector2f png_tmp = {2480, 2310};
    sfVector2f player_t = sfSprite_getPosition(all->p->my_player);
    sfVector2i player = {(int) player_t.x, (int) player_t.y};

    if (is_on(player, png, 40, 30)) {
        sfSprite_setPosition(all->dialogue_s[0].s->sprite,
        (sfVector2f){2810, 2470});
        sfRenderWindow_drawSprite(all->window,
        all->dialogue_s[0].s->sprite, NULL);
        if (all->event.key.code == sfKeyB) {
            all->statue_s++;
            math_conditional(all);
            sfRenderWindow_drawSprite(all->window,
            all->quest[4].s->sprite, NULL);
        }
    }
    math_log(all);
}
