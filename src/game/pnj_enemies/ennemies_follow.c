/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-alexis.arduca
** File description:
** ennemies_follow
*/

#include "../../../include/my.h"

void follow_player(all_t *all, player_t *player, ennemy_t *ennemy, int i)
{
    if (player->x < ennemy->EnnemieX)
        ennemy->EnnemieX -= 2;
    if (player->x >= ennemy->EnnemieX + 60)
        ennemy->EnnemieX += 2;
    if (player->y < ennemy->EnnemieY)
        ennemy->EnnemieY -= 2;
    if (player->y >= ennemy->EnnemieY + 60)
        ennemy->EnnemieY += 2;
    sfSprite_setPosition(ennemy->enemy_s, (sfVector2f){ennemy->EnnemieX,
    ennemy->EnnemieY});
    if (player->x >= ennemy->EnnemieX - 80 &&
    player->x <= ennemy->EnnemieX + 80) {
        if (player->y >= ennemy->EnnemieY - 80 &&
        player->y <= ennemy->EnnemieY + 80)
            all->var[10] = i;
    }
}

void detect_adv(all_t *all, player_t *player, ennemy_t *ennemy, int i)
{
    if (player->x >= ennemy->EnnemieX - 180 &&
    player->x <= ennemy->EnnemieX + 200) {
        if (player->y >= ennemy->EnnemieY - 180 &&
        player->y <= ennemy->EnnemieY + 200)
            follow_player(all, player, ennemy, i);
    }
}
