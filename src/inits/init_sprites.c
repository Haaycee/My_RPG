/*
** EPITECH PROJECT, 2022
** B-MUL-100-MPL-1-1-myrunner-hades.cuisinier
** File description:
** init_sprites
*/

#include "my.h"

sprite_t *init_sprite(char *pathname, sfVector2f pos, sfIntRect rect)
{
    sprite_t *new_sprite = malloc(sizeof(sprite_t));

    new_sprite->texture = sfTexture_createFromFile(pathname, NULL);
    new_sprite->sprite = sfSprite_create();
    new_sprite->position.x = pos.x;
    new_sprite->position.y = pos.y;
    new_sprite->rect.top = rect.top;
    new_sprite->rect.left = rect.left;
    new_sprite->rect.width = rect.width;
    new_sprite->rect.height = rect.height;
    new_sprite->offset = rect.width;
    sfSprite_setTexture(new_sprite->sprite, new_sprite->texture, sfTrue);
    sfSprite_setPosition(new_sprite->sprite, new_sprite->position);
    sfSprite_setTextureRect(new_sprite->sprite, rect);
    return new_sprite;
}
