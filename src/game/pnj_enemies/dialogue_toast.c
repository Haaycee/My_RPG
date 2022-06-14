/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-alexis.arduca
** File description:
** dialogue_toast.c
*/

#include "my.h"

static void toast_conditional(all_t *all)
{
    if (all->toast_t >= 1) {
        sfSprite_setPosition(all->dialogue_s[4].s->sprite, \
        sfRenderWindow_mapPixelToCoords(all->window, \
        (sfVector2i){830 + (0 * 200), 780}, all->camera));
        sfRenderWindow_drawSprite(all->window,
        all->dialogue_s[4].s->sprite, NULL);
        all->p->strength += 2;
    } else {
        sfSprite_setPosition(all->dialogue_s[3].s->sprite, \
        sfRenderWindow_mapPixelToCoords(all->window, \
        (sfVector2i){830 + (0 * 200), 780}, all->camera));
        sfRenderWindow_drawSprite(all->window,
        all->dialogue_s[3].s->sprite, NULL);
    }
    if (all->toast_s >= 1) {
        sfSprite_setPosition(all->quest[3].s->sprite, \
        sfRenderWindow_mapPixelToCoords(all->window, \
        (sfVector2i){0 + (0 * 100), 0}, all->camera));
        sfRenderWindow_drawSprite(all->window, all->quest[3].s->sprite, NULL);
    }
}

static void toast_log(all_t *all)
{
    sfVector2f png_tmp = {3530, 2350};
    sfVector2f player_t = sfSprite_getPosition(all->p->my_player);
    sfVector2i player = {(int) player_t.x, (int) player_t.y};

    if (all->toast_s != 0 && is_on(player, png_tmp, 40, 30) &&
    all->event.key.code == sfKeyB) {
        all->toast_t++;
        sfSprite_setPosition(all->quest[3].s->sprite, \
        sfRenderWindow_mapPixelToCoords(all->window, \
        (sfVector2i){0 + (0 * 100), 0}, all->camera));
        sfRenderWindow_drawSprite(all->window,
        all->quest[3].s->sprite, NULL);
        sfSprite_setPosition(all->dialogue_s[0].s->sprite,
        (sfVector2f){2810, 2470});
        sfRenderWindow_drawSprite(all->window,
        all->dialogue_s[3].s->sprite, NULL);
    }
}

void dialogue_toast(all_t *all)
{
    sfVector2f png = {3460, 2290};
    sfVector2f png_tmp = {3530, 2350};
    sfVector2f player_t = sfSprite_getPosition(all->p->my_player);
    sfVector2i player = {(int) player_t.x, (int) player_t.y};

    if (is_on(player, png, 40, 30)) {
        sfSprite_setPosition(all->dialogue_s[0].s->sprite,
        (sfVector2f){3460, 2290});
        sfRenderWindow_drawSprite(all->window,
        all->dialogue_s[0].s->sprite, NULL);
        if (all->event.key.code == sfKeyB) {
            all->toast_s++;
            toast_conditional(all);
        }
    }
    toast_log(all);
}
