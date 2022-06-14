/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-alexis.arduca
** File description:
** player
*/

#include "my.h"

void animation_left_and_right(all_t *all)
{
    all->p->rect_p.left += 20;
    if (all->p->rect_p.left == 160)
        all->p->rect_p.left = 0;
    sfSprite_setTextureRect(all->p->my_player, all->p->rect_p);
}

void animation_top_and_down(all_t *all)
{
    all->p->rect_p2.left += 20;
    if (all->p->rect_p2.left == 160)
        all->p->rect_p2.left = 0;
    sfSprite_setTextureRect(all->p->my_player, all->p->rect_p2);
}

void player_moovement2(all_t *all)
{
    if (sfKeyboard_isKeyPressed(all->cmd->down)) {
        change_texture(all, "src/assets/img/p_f.png");
        animation_top_and_down(all);
        if (!check_collision(all, all->p->x / 16, (all->p->y + 10) / 16)) {
            sfSprite_move(all->p->my_player, (sfVector2f){0, 10});
            all->p->y += 10;
        }
        all->p->PersoX = 2;
    }
    if (sfKeyboard_isKeyPressed(all->cmd->right)) {
        change_texture(all, "src/assets/img/p_r.png");
        animation_left_and_right(all);
        if (!check_collision(all, (all->p->x + 10) / 16, all->p->y / 16)) {
            sfSprite_move(all->p->my_player, (sfVector2f){10, 0});
            all->p->x += 10;
        }
        all->p->PersoX = 3;
    }
}

void player_moovement(all_t *all)
{
    if (sfKeyboard_isKeyPressed(all->cmd->up)) {
        change_texture(all, "src/assets/img/p_b.png");
        animation_top_and_down(all);
        if (!check_collision(all, all->p->x / 16, (all->p->y - 10) / 16)) {
            sfSprite_move(all->p->my_player, (sfVector2f){0, -10});
            all->p->y -= 10;
        }
        all->p->PersoX = 0;
    }
    if (sfKeyboard_isKeyPressed(all->cmd->left)) {
        change_texture(all, "src/assets/img/p_l.png");
        animation_left_and_right(all);
        if (!check_collision(all, (all->p->x - 10) / 16, all->p->y / 16)) {
            sfSprite_move(all->p->my_player, (sfVector2f){-10, 0});
            all->p->x -= 10;
        }
        all->p->PersoX = 1;
    }
    player_moovement2(all);
    sfClock_restart(all->clock[0]);
}
