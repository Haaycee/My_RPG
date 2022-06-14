/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-alexis.arduca
** File description:
** ennemy_stats
*/

#include "../../../include/my.h"

void stat_ennemy(all_t *all)
{
    all->ennemy[0]->health = 3;
    all->ennemy[0]->strenght = 1;
    all->ennemy[0]->level = 1;
}

void stat_boss(all_t *all)
{
    all->ennemy[0]->health = 30;
    all->ennemy[0]->strenght = 3;
    all->ennemy[0]->level = 10;
}

void ennemy_health(all_t *all)
{
    stat_ennemy(all);
    if (all->p->PersoX == all->ennemy[0]->EnnemieX &&
    all->p->PersoX == all->ennemy[0]->EnnemieX) {
        if (all->p->PersoY == all->ennemy[0]->EnnemieY &&
    all->p->PersoY == all->ennemy[0]->EnnemieY)
        all->ennemy[0]->health -= 1;
    }
}

void boss_health(all_t *all)
{
    stat_boss(all);
    if (all->p->PersoX == all->ennemy[0]->EnnemieX &&
    all->p->PersoX == all->ennemy[0]->EnnemieX) {
        if (all->p->PersoY == all->ennemy[0]->EnnemieY &&
        all->p->PersoY == all->ennemy[0]->EnnemieY)
            all->ennemy[0]->boss_health -= 1;
    }
}
