/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-alexis.arduca
** File description:
** init_ennemy
*/

#include "my.h"

void init_ennemy(all_t *all, int i, char *path, sfVector2f pos)
{
    all->ennemy[i] = malloc(sizeof(ennemy_t));
    all->ennemy[i]->enemy_s = sfSprite_create();
    all->ennemy[i]->enemy_t = sfTexture_createFromFile(path, sfFalse);
    all->ennemy[i]->EnnemieX = pos.x;
    all->ennemy[i]->EnnemieY = pos.y;
    all->ennemy[i]->ennemy_health = 10;
    all->ennemy[i]->strenght = 5;
    sfSprite_setTexture(all->ennemy[i]->enemy_s, all->ennemy[i]->enemy_t,
    sfFalse);
    sfSprite_setPosition(all->ennemy[i]->enemy_s, pos);
}

void init_ennemy2(all_t *all, int i, char *path, sfVector2f pos)
{
    all->ennemy[i] = malloc(sizeof(ennemy_t));
    all->ennemy[i]->enemy_s = sfSprite_create();
    all->ennemy[i]->enemy_t = sfTexture_createFromFile(path, sfFalse);
    all->ennemy[i]->EnnemieX = pos.x;
    all->ennemy[i]->EnnemieY = pos.y;
    all->ennemy[i]->ennemy_health = 5;
    all->ennemy[i]->strenght = 2;
    all->ennemy[i]->rect = (sfIntRect){0, 0, 70, 65};
    sfSprite_setTexture(all->ennemy[i]->enemy_s, all->ennemy[i]->enemy_t,
    sfFalse);
    sfSprite_setTextureRect(all->ennemy[i]->enemy_s, all->ennemy[i]->rect);
    sfSprite_setPosition(all->ennemy[i]->enemy_s, pos);
}
