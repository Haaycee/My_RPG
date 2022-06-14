/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-alexis.arduca
** File description:
** init_player
*/

#include "my.h"

sfText *text_battle(sfText *text, char *line, sfVector2f pos, all_t *all)
{
    text = sfText_create();

    sfText_setPosition(text, pos);
    sfText_setString(text, line);
    sfText_setFont(text, all->cmd->font);
    sfText_setCharacterSize(text, 20);
    sfText_setColor(text, sfBlack);
    return (text);
}

void set_fight_sprite2(all_t *all)
{
    all->fight->slash_s = sfSprite_create();
    all->fight->slash_t =
    sfTexture_createFromFile("src/assets/img/slash.png", sfFalse);
    sfSprite_setTexture(all->fight->slash_s, all->fight->slash_t, sfFalse);
    sfSprite_setPosition(all->fight->slash_s, (sfVector2f){1350, 500});
    all->fight->rect_slash = (sfIntRect){0, 0, 119, 121};
    sfSprite_setTextureRect(all->fight->slash_s, all->fight->rect_slash);
    all->fight->shoot_s = sfSprite_create();
    all->fight->shoot_t =
    sfTexture_createFromFile("src/assets/img/shoot.png", sfFalse);
    sfSprite_setTexture(all->fight->shoot_s, all->fight->shoot_t, sfFalse);
    all->fight->pos_s = (sfVector2f){410, 700};
    sfSprite_setPosition(all->fight->shoot_s, all->fight->pos_s);
}

void set_fight_sprite(all_t *all)
{
    all->fight->fight_t =
    sfTexture_createFromFile("src/assets/img/fight.jpg", sfFalse);
    all->fight->menu_fight_t =
    sfTexture_createFromFile("src/assets/img/battle_opt.png", sfFalse);
    all->fight->menu_atq_t =
    sfTexture_createFromFile("src/assets/img/battle_atq.png", sfFalse);
    all->fight->fire_t =
    sfTexture_createFromFile("src/assets/img/fire.png", sfFalse);
    sfSprite_setTexture(all->fight->fight_s, all->fight->fight_t, sfFalse);
    sfSprite_setTexture(all->fight->menu_fight_s, all->fight->menu_fight_t,
    sfFalse);
    sfSprite_setTexture(all->fight->menu_atq_s, all->fight->menu_atq_t,
    sfFalse);
    sfSprite_setTexture(all->fight->fire_s, all->fight->fire_t, sfFalse);
    all->fight->rect_f = (sfIntRect){0, 0, 234, 149};
    sfSprite_setTextureRect(all->fight->fire_s, all->fight->rect_f);
    all->fight->pos_f = (sfVector2f){1300, 500};
    set_fight_sprite2(all);
}

void set_enn(all_t *all)
{
    init_ennemy(all, 0, "src/assets/img/alien.png",
    (sfVector2f){50, 700});
    init_ennemy(all, 1, "src/assets/img/alien.png",
    (sfVector2f){50, 700});
    for (int i = 2; i < 4; i++)
        init_ennemy2(all, i, "src/assets/img/little_alien.png",
        (sfVector2f){rand() % 1000 + 2000, rand() % 400 + 700});
}

void init_fight(all_t *all)
{
    all->fight = malloc(sizeof(fight_t));
    all->fight->enemy = malloc(sizeof(ennemy_t));
    all->fight->p = all->p;
    all->fight->turn = 0;
    all->fight->life1_s = sfSprite_create();
    all->fight->life2_s = sfSprite_create();
    all->fight->fight_s = sfSprite_create();
    all->fight->opponent = sfSprite_create();
    all->fight->menu_fight_s = sfSprite_create();
    all->fight->menu_atq_s = sfSprite_create();
    all->fight->fire_s = sfSprite_create();
    all->fight->atq_pi = text_battle(all->fight->atq_pi, "Shoot",
    (sfVector2f){240, 140}, all);
    all->fight->atq_sw = text_battle(all->fight->atq_sw, "Sword Charge",
    (sfVector2f){240, 243}, all);
    all->fight->shield = text_battle(all->fight->shield, "Shield",
    (sfVector2f){240, 340}, all);
    set_enn(all);
    set_fight_sprite(all);
}
