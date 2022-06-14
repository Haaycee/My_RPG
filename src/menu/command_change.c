/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-alexis.arduca
** File description:
** command_change
*/

#include "my.h"

void click_cmd2(all_t *all)
{
    if (all->pos.y >= 550 && all->pos.y < 600) {
        all->var[2] = all->cmd->right;
        all->var[3] = 2;
    }
    if (all->pos.y >= 650 && all->pos.y < 700) {
        all->var[2] = all->cmd->attack;
        all->var[3] = 5;
    }
    if (all->pos.y >= 750 && all->pos.y < 800) {
        all->var[2] = all->cmd->obj[0];
        all->var[3] = 6;
    }
    if (all->pos.y >= 850 && all->pos.y < 900) {
        all->var[2] = all->cmd->obj[1];
        all->var[3] = 7;
    }
    if (all->pos.y >= 950 && all->pos.y < 1000) {
        all->var[2] = all->cmd->inv;
        all->var[3] = 8;
    }
}

void click_cmd(all_t *all)
{
    if (all->pos.x >= 30 && all->pos.x < 150) {
        if (all->pos.y >= 250 && all->pos.y < 300) {
            all->var[2] = all->cmd->up;
            all->var[3] = 1;
        }
        if (all->pos.y >= 350 && all->pos.y < 400) {
            all->var[2] = all->cmd->left;
            all->var[3] = 4;
        }
        if (all->pos.y >= 450 && all->pos.y < 500) {
            all->var[2] = all->cmd->down;
            all->var[3] = 3;
        }
        click_cmd2(all);
    }
}

void command_edit_menu2(all_t *all)
{
    sfRenderWindow_drawText(all->window, all->cmd->up_txt, NULL);
    sfRenderWindow_drawText(all->window, all->cmd->down_txt, NULL);
    sfRenderWindow_drawText(all->window, all->cmd->left_txt, NULL);
    sfRenderWindow_drawText(all->window, all->cmd->right_txt, NULL);
    sfRenderWindow_drawText(all->window, all->cmd->obj_txt[0], NULL);
    sfRenderWindow_drawText(all->window, all->cmd->obj_txt[1], NULL);
    sfRenderWindow_drawText(all->window, all->cmd->obj_text[0], NULL);
    sfRenderWindow_drawText(all->window, all->cmd->obj_text[1], NULL);
    sfRenderWindow_drawText(all->window, all->cmd->inv_txt, NULL);
    sfRenderWindow_drawText(all->window, all->cmd->inv_text, NULL);
}

void cmd_click(all_t *all)
{
    if (all->pos.y >= 800 && all->pos.y <= 1000) {
        all->var[7] = 0;
    }
}

void command_edit_menu(all_t *all)
{
    if (all->event.type == sfEvtMouseButtonReleased)
        click_cmd(all);
    sfRenderWindow_drawSprite(all->window, all->menu->spr[2].sprite, NULL);
    sfRenderWindow_drawText(all->window, all->cmd->attack_text, NULL);
    sfRenderWindow_drawText(all->window, all->cmd->up_text, NULL);
    sfRenderWindow_drawText(all->window, all->cmd->down_text, NULL);
    sfRenderWindow_drawText(all->window, all->cmd->left_text, NULL);
    sfRenderWindow_drawText(all->window, all->cmd->right_text, NULL);
    sfRenderWindow_drawText(all->window, all->cmd->attack_txt, NULL);
    command_edit_menu2(all);
    if (all->var[3] != 0)
        sfRenderWindow_drawText(all->window, all->cmd->text, NULL);
    if (all->event.type == sfEvtMouseButtonReleased) {
        if (all->pos.x >= 1800 && all->pos.x <= 2000)
            cmd_click(all);
    }
}
