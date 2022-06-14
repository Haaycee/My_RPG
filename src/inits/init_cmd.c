/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-alexis.arduca
** File description:
** init_all
*/

#include "my.h"

command_t *init_cmd2(command_t *cmd)
{
    cmd->obj_txt[0] = init_font(cmd->obj[0], (sfVector2f){180, 750}, 10, cmd);
    cmd->obj_txt[1] = init_font(cmd->obj[1], (sfVector2f){180, 850}, 10, cmd);
    cmd->inv_txt = init_font(cmd->inv, (sfVector2f){180, 950}, 10, cmd);
    cmd->up_text = init_text(cmd, "UP:", (sfVector2f){30, 250}, 30);
    cmd->down_text = init_text(cmd, "Down:", (sfVector2f){30, 350}, 30);
    cmd->right_text = init_text(cmd, "Right:", (sfVector2f){30, 450}, 30);
    cmd->left_text = init_text(cmd, "Left:", (sfVector2f){30, 550}, 30);
    cmd->attack_text = init_text(cmd, "Attack:", (sfVector2f){30, 650}, 30);
    cmd->text = init_text(cmd, "Press Any Key", (sfVector2f){700, 50}, 50);
    cmd->obj_text[0] = init_text(cmd, "Object 1:", (sfVector2f){30, 750}, 30);
    cmd->obj_text[1] = init_text(cmd, "Object 2:", (sfVector2f){30, 850}, 30);
    cmd->inv_text = init_text(cmd, "Open Inv:", (sfVector2f){30, 950}, 30);
}

command_t *init_cmd(command_t *cmd)
{
    cmd = malloc(sizeof(command_t));

    cmd->up = sfKeyZ;
    cmd->left = sfKeyQ;
    cmd->right = sfKeyD;
    cmd->down = sfKeyS;
    cmd->attack = sfKeyA;
    cmd->obj[0] = sfKeyW;
    cmd->obj[1] = sfKeyX;
    cmd->inv = sfKeyE;
    cmd->font = sfFont_createFromFile("src/assets/form.ttf");
    cmd->up_txt = init_font(cmd->up, (sfVector2f){180, 250}, 10, cmd);
    cmd->left_txt = init_font(cmd->left, (sfVector2f){180, 550}, 10, cmd);
    cmd->right_txt = init_font(cmd->right, (sfVector2f){180, 450}, 10, cmd);
    cmd->down_txt = init_font(cmd->down, (sfVector2f){180, 350}, 10, cmd);
    cmd->attack_txt = init_font(cmd->attack, (sfVector2f){180, 650}, 10, cmd);
    init_cmd2(cmd);
    return (cmd);
}
