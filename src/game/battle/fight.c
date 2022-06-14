/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-alexis.arduca
** File description:
** fight_game
*/

#include "my.h"

void battle_menu_click(all_t *all)
{
    if (all->pos.x > 800 && all->pos.x < 920) {
        if (all->pos.y > 880 && all->pos.y < 910)
            all->var[11] = 1;
    }
    if (all->pos.x > 1000 && all->pos.x < 1120) {
        if (all->pos.y > 880 && all->pos.y < 910)
            all->var[11] = 2;
    }
    if (all->pos.x > 1200 && all->pos.x < 1320) {
        if (all->pos.y > 880 && all->pos.y < 910)
            all->var[11] = 3;
    }
    sfClock_restart(all->clock[1]);
}

void set_pos_gui_battle(all_t *all, ennemy_t *ennemy)
{
    if (all->var[12] == 0) {
        sfSprite_setPosition(all->fight->p->my_player, (sfVector2f){400, 700});
        all->var[12] = 1;
        all->fight->pos_p = (sfVector2f){400, 700};
    } else
        sfSprite_setPosition(all->p->my_player, all->fight->pos_p);
    sfSprite_setPosition(all->fight->menu_fight_s, (sfVector2f){700, 850});
    sfSprite_setPosition(all->fight->menu_atq_s, (sfVector2f){100, 80});
    sfSprite_setPosition(all->ath[0].s->sprite, (sfVector2f){50, 800});
    if (all->var[10] == 1)
        sfSprite_setPosition(ennemy->enemy_s, (sfVector2f){1300, 400});
    else
        sfSprite_setPosition(ennemy->enemy_s, (sfVector2f){1400, 500});
}

void menu_select(all_t *all, ennemy_t *ennemy)
{
    if (all->var[11] == 1)
        menu_attack(all);
    if (all->var[11] == 2)
        menu_inv(all);
    if (all->var[11] == 3)
        leave(all);
    if (ennemy->ennemy_health <= 0) {
        if (all->var[10] == 1)
            sfRenderWindow_close(all->window);
        sfView_reset(all->camera, all->cam_rect);
        sfSprite_setPosition(all->p->my_player,
        (sfVector2f){all->p->x, all->p->y});
        all->var[10] = 0;
        all->var[11] = 0;
        all->var[12] = 0;
    } else if (all->p->health <= 0)
        death_reset(all);
}

void moov_player(all_t *all)
{
    if (sfKeyboard_isKeyPressed(all->cmd->up)) {
        if (all->fight->pos_p.y > 590)
            all->fight->pos_p.y -= 10;
        sfClock_restart(all->clock[1]);
    } else if (sfKeyboard_isKeyPressed(all->cmd->down)) {
        if (all->fight->pos_p.y < 810)
            all->fight->pos_p.y += 10;
        sfClock_restart(all->clock[1]);
    }
    if (sfKeyboard_isKeyPressed(all->cmd->right)) {
        if (all->fight->pos_p.x < 400)
            all->fight->pos_p.x += 10;
        sfClock_restart(all->clock[1]);
    } else if (sfKeyboard_isKeyPressed(all->cmd->left)) {
        all->fight->pos_p.x -= 10;
        sfSprite_move(all->p->my_player, (sfVector2f){-10, 0});
        if (all->fight->pos_p.x < -50)
            leave(all);
        sfClock_restart(all->clock[1]);
    }
}

void fight_display(all_t *all, ennemy_t *ennemy)
{
    all->time[1] = sfClock_getElapsedTime(all->clock[1]);
    all->seconds[1] = all->time[1].microseconds / 1000000.0;
    set_pos_gui_battle(all, ennemy);
    sfRenderWindow_clear(all->window, sfBlack);
    sfView_reset(all->camera, (sfFloatRect){0, 0, 1920, 1020});
    sfRenderWindow_drawSprite(all->window, all->fight->fight_s, NULL);
    sfRenderWindow_drawSprite(all->window, all->fight->p->my_player, NULL);
    sfRenderWindow_drawSprite(all->window, ennemy->enemy_s, NULL);
    sfRenderWindow_drawSprite(all->window, all->fight->menu_fight_s, NULL);
    sfRenderWindow_drawSprite(all->window, all->ath[0].s->sprite, NULL);
    if (all->var[13] == 1)
        player_attack_battle(all, ennemy);
    if (all->fight->turn == 1)
        boss_attack(all);
    if (all->seconds[1] >= 0.05)
        moov_player(all);
    if (all->event.type == sfEvtMouseButtonPressed && all->seconds[1] >= 0.5)
        battle_menu_click(all);
    menu_select(all, ennemy);
    sfRenderWindow_display(all->window);
}
