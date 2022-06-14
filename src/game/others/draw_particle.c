/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-alexis.arduca
** File description:
** draw_particule
*/

#include "../../../include/my.h"

void manage_key_window(all_t *all)
{
    sfVector2i pos;

    pos = sfMouse_getPositionRenderWindow(all->window);
    add_particle(&all->screen->particle_environment, all->screen->particle,
    10, (sfVector2f){pos.x, pos.y});
}

void display_window(all_t *all)
{
    for (size_t index = 0; index != PARICULE_MAX; index++)
        update_particle(&all->screen->particle_environment,
        &all->screen->particle[index]);
    for (size_t index = 0; index != PARICULE_MAX; index++)
        display_particle(all, &all->screen->particle[index],
        all->screen->particle_environment.circle_shape);
}

int show_particles(all_t *all)
{
    srand(time(NULL));

    display_window(all);
    return (0);
}

void particle_conditions(const particle_environment_t *particle_environment,
particle_t *particule, const size_t particle_num, const sfVector2f pos)
{
    for (int j = 0; j < PARICULE_MAX; j++) {
        if (particule[j].living == false) {
            init_particle(particle_environment, &particule[j], pos);
            particule[j].living = true;
        }
    }
}

char *int_to_char(int nb)
{
    int len = 0;
    int stock = nb;
    char *str;

    while (stock > 0) {
        stock /= 10;
        len++;
    }
    str = malloc(sizeof(*str) * (len + 1));
    str[len] = '\0';
    while (len--) {
        str[len] = nb % 10 + '0';
        nb /= 10;
    }
    return (str);
}
