/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-alexis.arduca
** File description:
** pnj_interaction
*/

#include "../../../include/my.h"

void zoom(all_t *all)
{
    if (all->event.type == sfEvtKeyReleased && all->seconds[0] >= 0.05 &&
    all->event.key.code == sfKeyO && all->cam_rect.width > 1400) {
        all->cam_rect.width -= 5;
        all->cam_rect.height -= 5;
        sfClock_restart(all->clock[0]);
    } else if (all->event.type == sfEvtKeyReleased && all->seconds[0]
    >= 0.05 && all->event.key.code == sfKeyP && all->cam_rect.width < 1900) {
        all->cam_rect.width += 5;
        all->cam_rect.height += 5;
        sfClock_restart(all->clock[0]);
    }
}
