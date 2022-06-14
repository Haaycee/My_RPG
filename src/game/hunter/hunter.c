/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-alexis.arduca
** File description:
** hunter
*/

#include "my.h"

static void event(all_t *all)
{
    if (all->event.type == sfEvtClosed)
        sfRenderWindow_close(all->window);
    for (int i = 0; i < JORDY; i++) {
        if (is_on(all->pos, sfSprite_getPosition(
        all->hunter[i].hunter_s->sprite), 75, 55) &&
        all->event.type == sfEvtMouseButtonPressed) {
            sfSprite_setPosition(all->hunter[i].hunter_s->sprite,
            (sfVector2f) {-20, rand() % 800 + 100});
            all->p->strength += 1;
            all->nb_enemy = all->nb_enemy >= 50 ? 50 : all->nb_enemy + 1;
        }
    }
}

static void conditions(all_t *all)
{
    if (all->lifes <= 0) {
        all->lifes = 3;
        all->state = MENU;
        sfMusic_play(all->music);
        return;
    }
    if (all->seconds[0] > 0.15) {
        for (int i = 0; i < all->nb_enemy; i++) {
            sfSprite_move(all->hunter[i].hunter_s->sprite,
            (sfVector2f) {all->hunter[i].speed, 0});
            sfSound_play(all->hunter[i].mos_sound);
        }
        sfClock_restart(all->clock[0]);
    }
}

void hunter(all_t *all)
{
    sfVector2f t;
    sfRenderWindow_clear(all->window, sfMagenta);
    all->time[0] = sfClock_getElapsedTime(all->clock[0]);
    all->seconds[0] = all->time[0].microseconds / 1000000.0;
    conditions(all);
    while (sfRenderWindow_pollEvent(all->window, &all->event))
        event(all);
    for (int i = 0; i < all->nb_enemy; i++) {
        sfRenderWindow_drawSprite(all->window,
        all->hunter[i].hunter_s->sprite, NULL);
        t = sfSprite_getPosition(all->hunter[i].hunter_s->sprite);
        if (sfSprite_getPosition(all->hunter[i].hunter_s->sprite).x > 1920) {
            all->lifes -= 1;
            sfSprite_setPosition(all->hunter[i].hunter_s->sprite,
            (sfVector2f) {-20, rand() % 800 + 100});
        }
    }
    sfRenderWindow_display(all->window);
}
