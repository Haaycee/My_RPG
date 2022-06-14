/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-alexis.arduca
** File description:
** init_hunter
*/

#include "my.h"

static hunter_t init_hunter(hunter_t new_hunter, sfSoundBuffer *buffer)
{
    new_hunter.pos.x = -100;
    new_hunter.pos.y = rand() % 800 + 100;
    new_hunter.speed = rand() % 50 + 10;
    new_hunter.hunter_s = init_sprite("./src/assets/mosquito/bzzzz.png",
    (sfVector2f) {new_hunter.pos.x, new_hunter.pos.y},
    (sfIntRect) {0, 0, 75, 55});
    new_hunter.mos_sound = sfSound_create();
    sfSound_setBuffer(new_hunter.mos_sound, buffer);
    return new_hunter;
}

all_t *init_all_hunter(all_t *all)
{
    srand(time(NULL));
    all->lifes = 3;
    all->nb_enemy = 1;
    all->buffer_h = sfSoundBuffer_createFromFile(
    "./src/assets/mosquito/bzzzzz.ogg");
    for (int i = 0; i < JORDY; i++) {
        all->hunter[i] = init_hunter(all->hunter[i], all->buffer_h);
    }
    return all;
}
