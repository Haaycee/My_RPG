/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-alexis.arduca
** File description:
** particule
*/

#include "../../../include/my.h"

void init_particle_environment(particle_environment_t *particle_environment,
const sfVector2f angle, const sfVector2f gravity, const sfUint8 alpha)
{
    particle_environment->angle_min = PARICULE_ANGLE_MIN;
    particle_environment->angle_max = PARICULE_ANGLE_MAX;
    particle_environment->gravity = gravity;
    particle_environment->alpha = alpha;
    particle_environment->speed = SPEED;
    particle_environment->circle_shape = sfCircleShape_create();
    particle_environment->clock = sfClock_create();
}

void init_particle(const particle_environment_t *particle_environment,
particle_t *particule, const sfVector2f pos)
{
    float angle = ((float)rand()/(float)(RAND_MAX)) *
    (particle_environment->angle_max - particle_environment->angle_min)
    + particle_environment->angle_min;
    particule->vel.x = cos(angle);
    particule->vel.y = sin(angle);
    particule->pos = (sfVector2f) {pos.x, pos.y};
    particule->living = 1;
    particule->radius = 1;
    particule->color = sfColor_fromRGBA(255, 0, 0, 255);
}

void display_particle(all_t *all, const particle_t *particule,
sfCircleShape *circle_shape)
{
    if (particule->living == true) {
        sfCircleShape_setPosition(circle_shape, particule->pos);
        sfCircleShape_setRadius(circle_shape, particule->radius);
        sfCircleShape_setFillColor(circle_shape, particule->color);
        sfRenderWindow_drawCircleShape(all->window, circle_shape, NULL);
    }
}

void update_particle(const particle_environment_t *particle_environment,
particle_t *particule)
{
    if (particule->living == true) {
        particule->color.a -= particle_environment->alpha;
        particule->vel.x += particle_environment->gravity.x;
        particule->vel.y += particle_environment->gravity.y;
        particule->pos.x += particule->vel.x * particle_environment->speed;
        particule->pos.y += particule->vel.y * particle_environment->speed;
        if (particule->color.a <= 0)
            particule->living = false;
    }
}

void add_particle(const particle_environment_t *particle_environment,
particle_t *particule, const size_t particle_num, const sfVector2f pos)
{
    for (int i = 0; i < particle_num; i++) {
        particle_conditions(particle_environment, particule,
        10, (sfVector2f){pos.x, pos.y});
    }
}
