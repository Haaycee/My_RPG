/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-alexis.arduca
** File description:
** settings
*/

#include "my.h"

static void over(all_t *all)
{
    if (!all->menu->btn[3].is_clicked) {
        if (is_on(all->pos, all->menu->btn[3].s->position, ARR_H, ARR_W))
            all->menu->btn[3].s->rect.left = ARR_W;
        else
            all->menu->btn[3].s->rect.left = 0;
        sfSprite_setTextureRect(all->menu->btn[3].s->sprite,
        all->menu->btn[3].s->rect);
    }
}

static void event(all_t *all)
{
    if (all->event.type == sfEvtClosed)
        sfRenderWindow_close(all->window);
    if (all->event.type == sfEvtKeyPressed
    && all->event.key.code == sfKeyEscape)
        all->state = MENU;
    if (all->event.type == sfEvtMouseButtonPressed && all->var[7] == 0)
        if (is_on(all->pos, all->menu->btn[3].s->position, ARR_H, ARR_W)) {
            sfSound_play(all->sound);
            all->menu->btn[3].is_clicked = true;
        }
    if (all->event.type == sfEvtMouseButtonReleased && all->var[7] == 0)
        if (all->menu->btn[3].is_clicked) {
            all->menu->btn[3].s->rect.left = 0;
            sfSprite_setTextureRect(all->menu->btn[3].s->sprite,
            all->menu->btn[3].s->rect);
            all->menu->btn[3].is_clicked = false;
            all->state = MENU;
        }
}

void draw_settings(all_t *all)
{
    sfRenderWindow_drawSprite(all->window, all->menu->spr[1].sprite, NULL);
    sfRenderWindow_drawSprite(all->window, all->menu->btn[3].s->sprite, NULL);
    sfRenderWindow_drawSprite(all->window, all->menu->btn[4].s->sprite, NULL);
    sfRenderWindow_drawSprite(all->window, all->menu->btn[5].s->sprite, NULL);
    if (all->event.type == sfEvtMouseButtonReleased) {
        detect_click(all, 0, 4);
        detect_click(all, 1, 5);
    }
    draw_curseur(all, 0, 4);
    draw_curseur(all, 1, 5);
}

void settings(all_t *all)
{
    sfView_reset(all->camera, (sfFloatRect){0, 0, 1920, 1020});
    over(all);
    if (all->event.type == sfEvtMouseButtonReleased &&
    all->pos.x >= 1800 && all->pos.x <= 2000) {
        if (all->pos.y >= 0 && all->pos.y <= 200)
            all->var[7] = 1;
    }
    while (sfRenderWindow_pollEvent(all->window, &all->event))
        event(all);
    if (all->event.type == sfEvtKeyReleased && all->var[3] > 0) {
        good_cmd(all->var[3], all, all->event.key.code);
        all->var[3] = 0;
    }
    sfRenderWindow_clear(all->window, sfBlack);
    if (all->var[7] == 1)
        command_edit_menu(all);
    else
        draw_settings(all);
    sfRenderWindow_setView(all->window, all->camera);
    sfRenderWindow_display(all->window);
}
