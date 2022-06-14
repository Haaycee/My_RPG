/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-alexis.arduca
** File description:
** draw_particule
*/

#include "../../../include/my.h"

void manage_key_window_r(all_t *all)
{
    sfVector2i pos;

    pos = sfMouse_getPositionRenderWindow(all->window);
    add_particle(&all->screen->particle_environment, all->screen->particle,
    10, (sfVector2f){pos.x, pos.y});
}

void display_window_r(all_t *all)
{
    for (size_t index = 0; index != PARICULE_MAX_D; index++)
        update_particle_r(&all->screen->particle_environment,
        &all->screen->particle[index]);
    for (size_t index = 0; index != PARICULE_MAX_D; index++)
        display_particle_r(all, &all->screen->particle[index],
        all->screen->particle_environment.circle_shape);
}

int show_particles_r(all_t *all)
{
    srand(time(NULL));

    display_window(all);
    return (0);
}

void particle_conditions_r(const particle_environment_t *particle_environment,
particle_t *particule, const size_t particle_num, const sfVector2f pos)
{
    for (int j = 0; j < PARICULE_MAX_D; j++) {
        if (particule[j].living == false) {
            init_particle_r(particle_environment, &particule[j], pos);
            particule[j].living = true;
        }
    }
}
