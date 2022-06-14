/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-alexis.arduca
** File description:
** menu
*/

#include "my.h"

void norm_detect(all_t *all, int i)
{
    if (all->var[i] == 0) {
        all->var[i] = 1;
    } else
        all->var[i] = 0;
}

void detect_click(all_t *all, int i, int j)
{
    if (all->pos.x >= all->menu->btn[j].s->position.x &&
    all->pos.x <= all->menu->btn[j].s->position.x + 50) {
        if (i == 0 && all->pos.y >= 870 && all->pos.y <= 870 + 100) {
            norm_detect(all, i);
        } else if (i == 1 && all->pos.y >= 585 && all->pos.y <= 585 + 100) {
            norm_detect(all, i);
        } else
            all->var[i] = 0;
    } else
        all->var[i] = 0;
}
