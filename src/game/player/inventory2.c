/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-alexis.arduca
** File description:
** ennemies_follow
*/

#include "../../../include/my.h"

void inventory_rechange(all_t *all, int x)
{
    if (all->event.type == sfEvtMouseButtonPressed) {
        if (x < 5) {
            sfSprite_setPosition(all->inv->obj_inv_s[x],
            sfRenderWindow_mapPixelToCoords(all->window,
            (sfVector2i){(80 * x + 20), 45}, all->camera));
        } else {
            sfSprite_setPosition(all->inv->obj_inv_s[x],
            sfRenderWindow_mapPixelToCoords(all->window,
            (sfVector2i){(80 * (x - 5) + 20), 45}, all->camera));
        }
        all->var[5] = 0;
    }
}
