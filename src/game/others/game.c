/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-alexis.arduca
** File description:
** initiator
*/

#include "my.h"

static void event(all_t *all)
{
    if (all->event.type == sfEvtClosed)
        sfRenderWindow_close(all->window);
    if (all->event.type == sfEvtKeyPressed
    && all->event.key.code == sfKeyEscape) {
        all->pause = !all->pause;
        all->var[6] = 0;
    }
    if (all->event.type == sfEvtKeyReleased &&
        all->event.key.code == all->cmd->inv && !all->pause) {
    if (all->var[6] == 0)
        all->var[6] = 1;
    else if (all->var[6] == 1)
        all->var[6] = 0;
    }
    if (all->event.type == sfEvtMouseButtonPressed)
        menu_quit(all);
    if (all->event.type == sfEvtMouseButtonReleased)
        buttons_pause(all);
}

static void sprites_follow(all_t *all)
{
    camera_player(all, (sfVector2f){all->p->x, all->p->y});
    sfSprite_setTextureRect(all->p->my_player, all->p->rect_p);
    sfSprite_setPosition(all->inv->slots_obj_s[0],
    sfRenderWindow_mapPixelToCoords(all->window,
    (sfVector2i){1700 + (0 * 100), 50}, all->camera));
    sfSprite_setPosition(all->inv->slots_obj_s[1],
    sfRenderWindow_mapPixelToCoords(all->window,
    (sfVector2i){1700 + (1 * 100), 50}, all->camera));
    sfSprite_setPosition(all->ath[0].s->sprite,
    sfRenderWindow_mapPixelToCoords(all->window,
    (sfVector2i){0 + (0 * 100), 800}, all->camera));
    sfRenderWindow_drawSprite(all->window, all->p->my_player, NULL);
}

void game_events_condition(all_t *all)
{
    if (all->var[10] > 0)
        fight_display(all, all->ennemy[all->var[10]]);
    if (all->pause && all->var[10] == 0)
        pause_draw(all);
    else if (all->seconds[0] >= 0.05 && all->var[10] == 0)
        player_moovement(all);
}

void game2(all_t *all)
{
    if (all->var[10] == 0) {
        sfRenderWindow_drawSprite(all->window, all->layer[1].sprite, NULL);
        detect_dialogue(all);
        if (all->pause)
            pause_draw(all);
        else if (all->var[6] == 1)
            main_inv(all);
        sfRenderWindow_drawSprite(all->window, all->inv->slots_obj_s[0], NULL);
        sfRenderWindow_drawSprite(all->window, all->inv->slots_obj_s[1], NULL);
        sfRenderWindow_drawSprite(all->window, all->ath[0].s->sprite, NULL);
        sfRenderWindow_drawSprite(all->window, all->pnj[0].s->sprite, NULL);
        sfRenderWindow_drawSprite(all->window, all->pnj[1].s->sprite, NULL);
        sfRenderWindow_display(all->window);
    }
}

void game(all_t *all)
{
    all->time[0] = sfClock_getElapsedTime(all->clock[0]);
    all->seconds[0] = all->time[0].microseconds / 1000000.0;
    while (sfRenderWindow_pollEvent(all->window, &all->event))
        event(all);
    sfRenderWindow_clear(all->window, sfBlack);
    sfRenderWindow_drawSprite(all->window, all->layer[0].sprite, NULL);
    detect_dialogue(all);
    sprites_follow(all);
    boss_spawning(all);
    ennemies_spawning(all);
    game_events_condition(all);
    zoom(all);
    pause_position(all);
    game2(all);
    sfText_setPosition(all->p->lvl,
    sfRenderWindow_mapPixelToCoords(all->window,
    (sfVector2i){200, 950}, all->camera));
    sfRenderWindow_drawText(all->window, all->p->lvl, NULL);
}
