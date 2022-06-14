/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-alexis.arduca
** File description:
** generator
*/

#include "my.h"

int generate_sprites_map2(all_t *all, int index, int i, int xy[2])
{
    for (int j = 0; j < all->map_width; j++) {
        if (all->map[i][j] < 21 && all->map[i][j] > 0) {
            all->game[index] = *init_sprite("src/assets/img/1.jpeg",
            (sfVector2f){xy[0], xy[1]}, (sfIntRect){0, 0, 32, 32});
            all->game[index].x = 42;
            index += 1;
        }
        if (all->map[i][j] > 20) {
            all->game[index] = *init_sprite("src/assets/img/2.png",
            (sfVector2f){xy[0], xy[1]}, (sfIntRect){0, 0, 32, 32});
            all->game[index].x = 42;
            index += 1;
        }
        xy[0] += 32;
    }
    return (index);
}

int generate_sprites_map(all_t *all)
{
    int xy[2];
    int index = 0;

    xy[0] = 0;
    xy[1] = 0;
    all->nb_sprites = 0;
    all->game = malloc(sizeof(all->game) * 10000);

    for (int i = 0; i < all->map_height; i++) {
        xy[0] = 0;
        index = generate_sprites_map2(all, index, i, xy);
        xy[1] += 32;
    }
    all->nb_sprites = index;
    return 0;
}
