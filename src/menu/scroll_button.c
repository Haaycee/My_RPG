/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-alexis.arduca
** File description:
** menu
*/

#include "my.h"

int value_scroll(int curseur, int val)
{
    int value = 0;
    int count = 1350;

    while (count <= curseur) {
        value += 1;
        count += 5;
    }
    if (value > 100)
        val = value / 10;
    else
        val = value;
    return (val);
}

void draw_curseur(all_t *all, int i, int j)
{
    if (all->var[i] == 1 && all->pos.x >= 1350 && all->pos.x <= 1800) {
        all->vol_m[i] = value_scroll(all->pos.x, all->vol_m[i]);
        all->menu->btn[j].s->position.x = all->pos.x;
        sfMusic_setVolume(all->music, all->vol_m[i]);
    }
    sfSprite_setPosition(all->menu->btn[j].s->sprite,
    all->menu->btn[j].s->position);
    sfRenderWindow_drawSprite(all->window, all->menu->btn[j].s->sprite, NULL);
}
