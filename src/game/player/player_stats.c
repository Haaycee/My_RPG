/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-alexis.arduca
** File description:
** health
*/

#include "../../../include/my.h"

void stat_player(all_t *all)
{
    all->p->exp = 0;
    all->p->level = 1;
    all->p->health = 3;
    all->p->strength = 1;
}

void player_health(all_t *all)
{
    stat_player(all);

    if (all->p->PersoX == all->ennemy[0]->EnnemieX &&
    all->p->PersoX == all->ennemy[0]->EnnemieX) {
        if (all->p->PersoY == all->ennemy[0]->EnnemieY &&
        all->p->PersoY == all->ennemy[0]->EnnemieY)
            all->p->health = all->p->health - all->ennemy[0]->strenght;
    }
}

void exp_player(all_t *all)
{
    all->p->exp += 5;
    if (all->p->exp == 20 * all->p->level) {
        all->p->level += 1;
        all->p->health += 1;
        all->p->strength += 1;
        all->p->exp = 0;
        sfText_setString(all->p->lvl, int_to_char(all->p->level));
    }
}
