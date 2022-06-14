/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-alexis.arduca
** File description:
** menu
*/

#include "my.h"

static void over(all_t *all)
{
    if (!all->menu->btn[3].is_clicked) {
        if (is_on(all->pos, all->menu->btn[3].s->position, ARR_H, ARR_W))
            all->menu->btn[3].s->rect.left = ARR_W;
        else
            all->menu->btn[3].s->rect.left = 0;
        sfSprite_setTextureRect(all->menu->btn[3].s->sprite,
        all->menu->btn[3].s->rect);
    }
}

static void event(all_t *all)
{
    if (all->event.type == sfEvtClosed)
        sfRenderWindow_close(all->window);
    if (all->event.type == sfEvtKeyPressed
    && all->event.key.code == sfKeyEscape)
        all->state = MENU;
    if (all->event.type == sfEvtMouseButtonPressed)
        if (is_on(all->pos, all->menu->btn[3].s->position, ARR_H, ARR_W)) {
            sfSound_play(all->sound);
            all->menu->btn[3].is_clicked = true;
        }
    if (all->event.type == sfEvtMouseButtonReleased)
        if (all->menu->btn[3].is_clicked) {
            all->menu->btn[3].s->rect.left = 0;
            sfSprite_setTextureRect(all->menu->btn[3].s->sprite,
            all->menu->btn[3].s->rect);
            all->menu->btn[3].is_clicked = false;
            all->state = MENU;
        }
}

void settings2(all_t *all)
{
    over(all);
    while (sfRenderWindow_pollEvent(all->window, &all->event))
        event(all);
    sfRenderWindow_clear(all->window, sfBlack);
    sfRenderWindow_drawSprite(all->window, all->menu->spr[2].sprite, NULL);
    sfRenderWindow_drawSprite(all->window, all->menu->btn[3].s->sprite, NULL);
    sfRenderWindow_drawText(all->window, all->cmd->attack_txt, NULL);
    sfRenderWindow_drawText(all->window, all->cmd->up_txt, NULL);
    sfRenderWindow_drawText(all->window, all->cmd->down_txt, NULL);
    sfRenderWindow_drawText(all->window, all->cmd->left_txt, NULL);
    sfRenderWindow_drawText(all->window, all->cmd->right_txt, NULL);
    sfRenderWindow_display(all->window);
}
