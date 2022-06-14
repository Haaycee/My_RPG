/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-alexis.arduca
** File description:
** init_all2
*/

#include "my.h"

void init_cinematic(all_t *all)
{
    all->cinematic[0].s = init_sprite("src/assets/img/menu.jpg",
    (sfVector2f){0, 0}, (sfIntRect){0, 0, 1920, 1080});
    all->cinematic[1].s = init_sprite("src/assets/img/menu.jpg",
    (sfVector2f){0, 0}, (sfIntRect){0, 0, 1920, 1080});
    all->state = CINEMATIC;
}

void ini_pnj(all_t *all)
{
    all->pnj[0].s = init_sprite("src/assets/img/front_pnj.png", \
    (sfVector2f){2850, 2510}, (sfIntRect){0, 0, 22, 20});
    all->pnj[1].s = init_sprite("src/assets/img/front_pnj.png", \
    (sfVector2f){3460, 2270}, (sfIntRect){0, 0, 22, 20});
}

void init_ath(all_t *all)
{
    all->ath[0].s = init_sprite("src/assets/img/Group1.png",
    (sfVector2f){500, 500}, (sfIntRect){0, 0, 1720, 1080});
}

void init_camera(all_t *all, sprite_t *sprite_p, player_t *perso)
{
    sfView *cam = sfView_createFromRect(all->cam_rect);
    sfSprite_setPosition(perso->my_player, sprite_p->position);
}
