/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-alexis.arduca
** File description:
** init_player
*/

#include "my.h"

player_t *init_p2(player_t *p)
{
    p->g = 0;
    p->PersoX = 0;
    p->level = 1;
    p->strength = 1;
    p->health = 5;
}

player_t *init_player(player_t *p)
{
    sfFont *font = sfFont_createFromFile("src/assets/form.ttf");
    p = malloc(sizeof(player_t));
    p->x = 400;
    p->y = 2400;
    p->rect_p = (sfIntRect){0, 0, 20, 20};
    p->my_player = sfSprite_create();
    p = init_p2(p);
    p->lvl = sfText_create();
    sfText_setString(p->lvl, "1");
    sfText_setFont(p->lvl, font);
    sfText_setCharacterSize(p->lvl, 30);
    sfText_setColor(p->lvl, sfBlack);
    sfSprite_setPosition(p->my_player, (sfVector2f){p->x, p->y});
    sfSprite_setTextureRect(p->my_player, p->rect_p);
    return (p);
}
