/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-alexis.arduca
** File description:
** destroy
*/

#include "my.h"

void destroy_inv(inventory_t *inv)
{
    sfSprite_destroy(inv->inv_s);
    sfTexture_destroy(inv->inv_t);
    for (int i = 0; i < OBJ; i++) {
        sfSprite_destroy(inv->obj_inv_s[i]);
        sfTexture_destroy(inv->obj_inv_t[i]);
    }
    sfSprite_destroy(inv->slots_obj_s[0]);
    sfSprite_destroy(inv->slots_obj_s[1]);
    sfTexture_destroy(inv->slots_obj_t[0]);
    sfTexture_destroy(inv->slots_obj_t[1]);
    sfText_destroy(inv->inv_txt);
}

void destroy_cmd(command_t *cmd)
{
    sfFont_destroy(cmd->font);
    sfText_destroy(cmd->text);
    sfText_destroy(cmd->up_txt);
    sfText_destroy(cmd->up_text);
    sfText_destroy(cmd->down_txt);
    sfText_destroy(cmd->down_text);
    sfText_destroy(cmd->left_txt);
    sfText_destroy(cmd->left_text);
    sfText_destroy(cmd->right_txt);
    sfText_destroy(cmd->right_text);
    sfText_destroy(cmd->attack_txt);
    sfText_destroy(cmd->attack_text);
    sfText_destroy(cmd->inv_txt);
    sfText_destroy(cmd->inv_text);
    for (int i = 0; i < 2; i++) {
        sfText_destroy(cmd->obj_txt[i]);
        sfText_destroy(cmd->obj_text[i]);
    }
}

void destroy_menu(all_t *all)
{
    for (int i = 0; i < 3; i++) {
        sfSprite_destroy(all->menu->spr[i].sprite);
        sfTexture_destroy(all->menu->spr[i].texture);
    }
    for (int i = 0; i < 5; i++) {
        sfSprite_destroy(all->menu->btn[i].s->sprite);
        sfTexture_destroy(all->menu->btn[i].s->texture);
    }
}
