/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-alexis.arduca
** File description:
** init_all
*/

#include "my.h"

void init_menu2(all_t *all)
{
    all->menu->spr[2] = *init_sprite("src/assets/img/menu_cmd.jpg",
    (sfVector2f){0, 0}, (sfIntRect){0, 0, 1920, 1080});
    for (int i = 0; i < BUTTONS_MENU; i++)
        all->menu->btn[i].is_clicked = false;
}

void init_menu(all_t *all)
{
    all->menu = malloc(sizeof(menu_t));

    all->menu->spr[0] = *init_sprite("src/assets/img/menu.jpg",
    (sfVector2f){0, 0}, (sfIntRect){0, 0, 1920, 1080});
    all->menu->spr[1] = *init_sprite("src/assets/img/options.png",
    (sfVector2f){0, 0}, (sfIntRect){0, 0, 1920, 1080});
    all->menu->btn[0].s = init_sprite("src/assets/img/play.png",
    (sfVector2f){720, 180}, (sfIntRect){0, 0, PLAY_W, PLAY_H});
    all->menu->btn[1].s = init_sprite("src/assets/img/settings.png",
    (sfVector2f){325, 240}, (sfIntRect){0, 0, SET_W, SET_H});
    all->menu->btn[2].s = init_sprite("src/assets/img/exit.png",
    (sfVector2f){1225, 240}, (sfIntRect){0, 0, EXIT_W, EXIT_H});
    all->menu->btn[3].s = init_sprite("src/assets/img/arrow.png",
    (sfVector2f){64, 855}, (sfIntRect){0, 0, ARR_W, ARR_H});
    all->menu->btn[4].s = init_sprite("src/assets/img/scroll.png",
    (sfVector2f){1560, 870}, (sfIntRect){0, 0, 50, 100});
    all->menu->btn[5].s = init_sprite("src/assets/img/scroll.png",
    (sfVector2f){1560, 585}, (sfIntRect){0, 0, 50, 100});
    init_menu2(all);
}
