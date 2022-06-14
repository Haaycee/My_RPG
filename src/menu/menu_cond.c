/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-alexis.arduca
** File description:
** menu_cond.c
*/

#include "my.h"

static void leave_menu_others2(all_t *all)
{
    if (is_on(all->pos, all->pause_s[4].s->position, 80, 352)
    && all->pause) {
        all->pause_s[4].s->rect.left = 352 * 2;
        sfSprite_setTextureRect(all->pause_s[4].s->sprite,
        all->pause_s[4].s->rect);
        sfSound_play(all->sound);
        all->pause_s[4].is_clicked = !all->pause_s[4].is_clicked;
    }
}

static void leave_menu_others(all_t *all)
{
    if (is_on(all->pos, all->pause_s[2].s->position, 80, 352) && all->pause) {
        all->pause_s[2].s->rect.left = 352 * 2;
        sfSprite_setTextureRect(all->pause_s[2].s->sprite,
        all->pause_s[2].s->rect);
        sfSound_play(all->sound);
        all->pause_s[2].is_clicked = !all->pause_s[2].is_clicked;
    }
    if (is_on(all->pos, all->pause_s[3].s->position, 80, 352) && all->pause) {
        all->pause_s[3].s->rect.left = 352 * 2;
        sfSprite_setTextureRect(all->pause_s[3].s->sprite,
        all->pause_s[3].s->rect);
        sfSound_play(all->sound);
        all->pause_s[3].is_clicked = !all->pause_s[3].is_clicked;
    }
    leave_menu_others2(all);
}

void leave_menu(all_t *all)
{
    if (is_on(all->pos, all->pause_s[0].s->position, 80, 352) && all->pause) {
        all->pause_s[0].s->rect.left = 352 * 2;
        sfSprite_setTextureRect(all->pause_s[0].s->sprite,
        all->pause_s[0].s->rect);
        sfSound_play(all->sound);
        all->pause_s[0].is_clicked = !all->pause_s[0].is_clicked;
    }
    if (is_on(all->pos, all->pause_s[1].s->position, 80, 352) && all->pause) {
        all->pause_s[1].s->rect.left = 352 * 2;
        sfSprite_setTextureRect(all->pause_s[1].s->sprite,
        all->pause_s[1].s->rect);
        sfSound_play(all->sound);
        all->pause_s[1].is_clicked = !all->pause_s[1].is_clicked;
    }
    leave_menu_others(all);
}

static void buttons_pause_others(all_t *all)
{
    if (all->pause_s[2].is_clicked) {
        all->pause_s[2].s->rect.left = 352;
        sfSprite_setTextureRect(all->pause_s[2].s->sprite,
        all->pause_s[2].s->rect);
    }
    if (all->pause_s[3].is_clicked) {
        all->pause_s[3].s->rect.left = 352;
        sfSprite_setTextureRect(all->pause_s[3].s->sprite,
        all->pause_s[3].s->rect);
        all->pause_s[3].is_clicked = false;
        sfRenderWindow_close(all->window);
    }
    if (all->pause_s[4].is_clicked) {
        all->pause_s[4].s->rect.left = 352;
        sfSprite_setTextureRect(all->pause_s[4].s->sprite,
        all->pause_s[4].s->rect);
        all->pause_s[4].is_clicked = false;
        all->state = MENU;
    }
}

void buttons_pause(all_t *all)
{
    if (all->pause_s[0].is_clicked) {
        all->pause_s[0].s->rect.left = 352;
        sfSprite_setTextureRect(all->pause_s[0].s->sprite,
        all->pause_s[0].s->rect);
        all->pause = false;
    }
    if (all->pause_s[1].is_clicked) {
        all->pause_s[1].s->rect.left = 352;
        sfSprite_setTextureRect(all->pause_s[1].s->sprite,
        all->pause_s[1].s->rect);
        all->pause_s[1].is_clicked = false;
        all->state = SETTINGS;
    }
    buttons_pause_others(all);
}
