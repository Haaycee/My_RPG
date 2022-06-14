/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-alexis.arduca
** File description:
** menu
*/

#include "my.h"

void buttons2(all_t *all)
{
    if (is_on(all->pos, all->menu->btn[2].s->position, EXIT_H, EXIT_W)) {
        all->menu->btn[2].s->rect.left = EXIT_W * 2;
        sfSprite_setTextureRect(all->menu->btn[2].s->sprite,
        all->menu->btn[2].s->rect);
        sfSound_play(all->sound);
        all->menu->btn[2].is_clicked = true;
    }
}

void buttons(all_t *all)
{
    if (is_on(all->pos, all->menu->btn[0].s->position, PLAY_H, PLAY_W)) {
        all->menu->btn[0].s->rect.left = PLAY_W * 2;
        sfSprite_setTextureRect(all->menu->btn[0].s->sprite,
        all->menu->btn[0].s->rect);
        sfSound_play(all->sound);
        all->menu->btn[0].is_clicked = true;
    }
    if (is_on(all->pos, all->menu->btn[1].s->position, SET_H, SET_W)) {
        all->menu->btn[1].s->rect.left = SET_W * 2;
        sfSprite_setTextureRect(all->menu->btn[1].s->sprite,
        all->menu->btn[1].s->rect);
        sfSound_play(all->sound);
        all->menu->btn[1].is_clicked = true;
    }
    buttons2(all);
}

void event_buttons2(all_t *all)
{
    if (all->menu->btn[2].is_clicked) {
        all->menu->btn[2].s->rect.left = EXIT_W;
        sfSprite_setTextureRect(all->menu->btn[2].s->sprite,
        all->menu->btn[2].s->rect);
        all->menu->btn[2].is_clicked = false;
        sfRenderWindow_close(all->window);
    }
}

void event_buttons(all_t *all)
{
    if (all->menu->btn[0].is_clicked) {
        all->menu->btn[0].s->rect.left = PLAY_W;
        sfSprite_setTextureRect(all->menu->btn[0].s->sprite,
        all->menu->btn[0].s->rect);
        all->menu->btn[0].is_clicked = false;
        sfMusic_stop(all->music);
        all->state = GAME;
    }
    if (all->menu->btn[1].is_clicked) {
        all->menu->btn[1].s->rect.left = SET_W;
        sfSprite_setTextureRect(all->menu->btn[1].s->sprite,
        all->menu->btn[1].s->rect);
        all->menu->btn[1].is_clicked = false;
        all->state = SETTINGS;
    }
    event_buttons2(all);
}
