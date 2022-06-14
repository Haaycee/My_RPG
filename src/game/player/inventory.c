/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-alexis.arduca
** File description:
** ennemies_follow
*/

#include "../../../include/my.h"

void obj_inv(int x, all_t *all)
{
    sfSprite_setPosition(all->inv->obj_inv_s[x],
    sfRenderWindow_mapPixelToCoords(all->window,
    (sfVector2i){all->pos.x, all->pos.y}, all->camera));
    all->var[5] = 1;
    all->var[4] = x;
}

void inventory_bot(all_t *all)
{
    if (all->pos.x > 20 && all->pos.x < 100) {
        if (all->pos.y > 120 && all->pos.y < 200)
            obj_inv(5, all);
    }
    if (all->pos.x > 110 && all->pos.x < 170) {
        if (all->pos.y > 120 && all->pos.y < 200)
            obj_inv(6, all);
    }
    if (all->pos.x > 180 && all->pos.x < 260) {
        if (all->pos.y > 120 && all->pos.y < 200)
            obj_inv(7, all);
    }
    if (all->pos.x > 270 && all->pos.x < 350) {
        if (all->pos.y > 120 && all->pos.y < 200)
            obj_inv(8, all);
    }
    if (all->pos.x > 360 && all->pos.x < 440) {
        if (all->pos.y > 120 && all->pos.y < 200)
            obj_inv(9, all);
    }
}

void inventory_top(all_t *all)
{
    if (all->pos.x > 20 && all->pos.x < 100) {
        if (all->pos.y > 30 && all->pos.y < 110)
            obj_inv(0, all);
    }
    if (all->pos.x > 110 && all->pos.x < 170) {
        if (all->pos.y > 30 && all->pos.y < 110)
            obj_inv(1, all);
    }
    if (all->pos.x > 180 && all->pos.x < 260) {
        if (all->pos.y > 30 && all->pos.y < 110)
            obj_inv(2, all);
    }
    if (all->pos.x > 270 && all->pos.x < 350) {
        if (all->pos.y > 30 && all->pos.y < 110)
            obj_inv(3, all);
    }
    if (all->pos.x > 360 && all->pos.x < 440) {
        if (all->pos.y > 30 && all->pos.y < 110)
            obj_inv(4, all);
    }
}

void draw_inv(all_t *all)
{
    all->worldMousePos = sfRenderWindow_mapPixelToCoords(all->window,
    all->pos, all->camera);
    all->worldPos = sfRenderWindow_mapPixelToCoords(all->window,
    (sfVector2i){0, 0}, all->camera);
    sfSprite_setPosition(all->inv->inv_s, all->worldPos);
    for (int i = 0; i < OBJ; i++) {
        if (i < 5) {
            sfSprite_setPosition(all->inv->obj_inv_s[i],
            sfRenderWindow_mapPixelToCoords(all->window,
            (sfVector2i){95 * i + 25, 55}, all->camera));
        } else {
            sfSprite_setPosition(all->inv->obj_inv_s[i],
            sfRenderWindow_mapPixelToCoords(all->window,
            (sfVector2i){95 * (i - 5) + 25, 155}, all->camera));
        }
    }
}

void main_inv(all_t *all)
{
    draw_inv(all);
    if (all->var[5] != 1 && all->event.type == sfEvtMouseButtonReleased) {
        inventory_top(all);
        inventory_bot(all);
    } else if (all->var[5] == 1) {
        sfSprite_setPosition(all->inv->obj_inv_s[all->var[4]],
        sfRenderWindow_mapPixelToCoords(all->window,
        (sfVector2i){all->pos.x, all->pos.y}, all->camera));
        inventory_rechange(all, all->var[4]);
    }
    sfRenderWindow_drawSprite(all->window, all->inv->inv_s, NULL);
    for (int i = 0; i < OBJ; i++)
        sfRenderWindow_drawSprite(all->window, all->inv->obj_inv_s[i], NULL);
}
