/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-alexis.arduca
** File description:
** loop
*/

#include "my.h"

int paricles_loop(all_t *all)
{
    all->screen = malloc(sizeof(screen_t));

    for (int i = 0; i < PARICULE_MAX; i++)
        all->screen->particle[i].living = 0;
    init_particle_environment(&all->screen->particle_environment,
    (sfVector2f){PARICULE_ANGLE_MIN, PARICULE_ANGLE_MAX},
    (sfVector2f){GRAVITY_X, GRAVITY_Y}, ALPHA);
    return 0;
}

int game_loop(all_t *all)
{
    if (all->state != HUNTER)
        sfMusic_play(all->music);
    paricles_loop(all);
    while (sfRenderWindow_isOpen(all->window) && all->state) {
        all->pos = sfMouse_getPosition((const sfWindow *) all->window);
        if (all->state == MENU) {
            menu(all);
            sfMusic_setVolume(all->music, all->vol_m[0]);
            sfMusic_setLoop(all->music, sfTrue);
        }
        if (all->state == GAME) {
            sfView_reset(all->camera, all->cam_rect);
            game(all);
        }
        if (all->state == HUNTER)
            hunter(all);
        if (all->state == SETTINGS)
            settings(all);
    }
    return 0;
}
