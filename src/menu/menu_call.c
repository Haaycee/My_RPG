/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-alexis.arduca
** File description:
** menu_filecond.c
*/

#include "my.h"

static void event(all_t *all)
{
    if (all->event.type == sfEvtClosed || (all->event.type ==
    sfEvtKeyPressed && all->event.key.code == sfKeyEscape))
        sfRenderWindow_close(all->window);
    if (all->event.type == sfEvtMouseButtonPressed)
        leave_menu(all);
}

static void over(all_t *all, int i)
{
    int height[] = {80, 80, 80, 80, 80};
    int width[] = {352, 352, 352, 352, 352};

    if (!all->menu->btn[i].is_clicked) {
        if (is_on(all->pos, all->pause_s[i].s->position, height[i],
        width[i]))
            all->pause_s[i].s->rect.left = width[i];
        else
            all->pause_s[i].s->rect.left = 0;
        sfSprite_setTextureRect(all->pause_s[i].s->sprite,
        all->pause_s[i].s->rect);
    }
}

void menu_quit(all_t *all)
{
    for (int i = 3; i < 5; i++)
        over(all, i);
    event(all);
}
