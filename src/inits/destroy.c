/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-alexis.arduca
** File description:
** destroy
*/

#include "my.h"

void destroy_all2(all_t *all)
{
    for (int i = 0; i < CLOCK; i++)
        sfClock_destroy(all->clock[i]);
    sfSound_destroy(all->sound);
    sfSoundBuffer_destroy(all->buffer);
    sfView_destroy(all->camera);
    sfView_destroy(all->mini_map);
    sfRenderWindow_destroy(all->window);
}

void destroy_battle(fight_t *fight)
{
    sfSprite_destroy(fight->opponent);
    sfSprite_destroy(fight->fight_s);
    sfSprite_destroy(fight->life1_s);
    sfSprite_destroy(fight->life2_s);
    sfSprite_destroy(fight->menu_fight_s);
    sfSprite_destroy(fight->menu_atq_s);
    sfSprite_destroy(fight->slash_s);
    sfSprite_destroy(fight->fire_s);
    sfTexture_destroy(fight->fight_t);
    sfTexture_destroy(fight->menu_fight_t);
    sfTexture_destroy(fight->fire_t);
    sfTexture_destroy(fight->slash_t);
    sfTexture_destroy(fight->menu_atq_t);
    sfText_destroy(fight->atq_pi);
    sfText_destroy(fight->atq_sw);
    sfText_destroy(fight->shield);
}

void destroy_ennemy(ennemy_t *ennemy)
{
    sfSprite_destroy(ennemy->enemy_s);
    sfTexture_destroy(ennemy->enemy_t);
}

void destroy_all(all_t *all)
{
    destroy_menu(all);
    destroy_cmd(all->cmd);
    destroy_battle(all->fight);
    destroy_inv(all->inv);
    for (int i = 0; i < 4; i++)
        destroy_ennemy(all->ennemy[i]);
    destroy_all2(all);
    free(all);
}
