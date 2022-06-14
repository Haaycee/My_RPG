/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-alexis.arduca
** File description:
** change_sprite
*/

#include "my.h"

void change_texture(all_t *all, char *filename)
{
    all->p->my_player2 = sfTexture_createFromFile(filename, NULL);
    sfSprite_setTexture(all->p->my_player, all->p->my_player2, sfFalse);
}
