/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-alexis.arduca
** File description:
** command_change
*/

#include "my.h"

void good_cmd2(int var, all_t *all, int cmd)
{
    if (var == 5) {
        all->cmd->attack = cmd;
        sfText_setString(all->cmd->attack_txt, my_strcommands(cmd));
    }
    if (var == 6) {
        all->cmd->obj[0] = cmd;
        sfText_setString(all->cmd->obj_txt[0], my_strcommands(cmd));
    }
    if (var == 7) {
        all->cmd->obj[1] = cmd;
        sfText_setString(all->cmd->obj_txt[1], my_strcommands(cmd));
    }
    if (var == 8) {
        all->cmd->inv = cmd;
        sfText_setString(all->cmd->inv_txt, my_strcommands(cmd));
    }
}

void good_cmd(int var, all_t *all, int cmd)
{
    if (var == 1) {
        all->cmd->up = cmd;
        sfText_setString(all->cmd->up_txt, my_strcommands(cmd));
    }
    if (var == 4) {
        all->cmd->down = cmd;
        sfText_setString(all->cmd->down_txt, my_strcommands(cmd));
    }
    if (var == 2) {
        all->cmd->left = cmd;
        sfText_setString(all->cmd->left_txt, my_strcommands(cmd));
    }
    if (var == 3) {
        all->cmd->right = cmd;
        sfText_setString(all->cmd->right_txt, my_strcommands(cmd));
    }
    good_cmd2(var, all, cmd);
}
