/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-alexis.arduca
** File description:
** menu
*/

#include "my.h"

static void event(all_t *all)
{
    if (all->event.type == sfEvtClosed || (all->event.type ==
    sfEvtKeyPressed && all->event.key.code == sfKeyEscape))
        sfRenderWindow_close(all->window);
    if (all->event.type == sfEvtMouseButtonPressed)
        buttons(all);
    if (all->event.type == sfEvtMouseButtonReleased)
        event_buttons(all);
    if (sfMouse_isButtonPressed(sfMouseLeft))
        manage_key_window(all);
    if (sfMouse_isButtonPressed(sfMouseRight))
        manage_key_window_r(all);
}

static void over(all_t *all, int i)
{
    int height[] = {PLAY_H, SET_H, EXIT_H};
    int width[] = {PLAY_W, SET_W, EXIT_W};

    if (!all->menu->btn[i].is_clicked) {
        if (is_on(all->pos, all->menu->btn[i].s->position, height[i],
        width[i]))
            all->menu->btn[i].s->rect.left = width[i];
        else
            all->menu->btn[i].s->rect.left = 0;
        sfSprite_setTextureRect(all->menu->btn[i].s->sprite,
        all->menu->btn[i].s->rect);
    }
}

void menu(all_t *all)
{
    sfView_reset(all->camera, (sfFloatRect){0, 0, 1920, 1020});
    for (int i = 0; i < 3; i++) {
        over(all, i);
    }
    while (sfRenderWindow_pollEvent(all->window, &all->event))
        event(all);
    sfRenderWindow_clear(all->window, sfBlack);
    sfRenderWindow_drawSprite(all->window, all->menu->spr[0].sprite, NULL);
    sfRenderWindow_drawSprite(all->window, all->menu->btn[0].s->sprite, NULL);
    sfRenderWindow_drawSprite(all->window, all->menu->btn[1].s->sprite, NULL);
    sfRenderWindow_drawSprite(all->window, all->menu->btn[2].s->sprite, NULL);
    sfRenderWindow_setView(all->window, all->camera);
    show_particles(all);
    show_particles_r(all);
    sfRenderWindow_display(all->window);
}
