/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-alexis.arduca
** File description:
** init_all
*/

#include "my.h"

static void init_pause(all_t *all)
{
    all->pause_s[0].s = init_sprite("src/assets/img/resume.png",
    (sfVector2f){780, 230}, (sfIntRect){0, 0, 352, 80});
    all->pause_s[0].is_clicked = false;
    all->pause_s[1].s = init_sprite("src/assets/img/setting.png",
    (sfVector2f){780, 420}, (sfIntRect){0, 0, 352, 80});
    all->pause_s[1].is_clicked = false;
    all->pause_s[2].s = init_sprite("src/assets/img/exits.png",
    (sfVector2f){780, 610}, (sfIntRect){0, 0, 352, 80});
    all->pause_s[2].is_clicked = false;
    all->pause_s[3].s = init_sprite("src/assets/img/leave_sprites.png",
    (sfVector2f){600, 700}, (sfIntRect){0, 0, 352, 80});
    all->pause_s[3].is_clicked = false;
    all->pause_s[4].s = init_sprite("src/assets/img/home_sprites.png",
    (sfVector2f){1000, 700}, (sfIntRect){0, 0, 360, 85});
    all->pause_s[4].is_clicked = false;
}

static void init_dialogue(all_t *all)
{
    all->layer[0] = *init_sprite("src/assets/img/layer_0.png",
    (sfVector2f){0, 0}, (sfIntRect){0, 0, 3840, 2704});
    all->layer[1] = *init_sprite("src/assets/img/layer_1.png",
    (sfVector2f){0, 0}, (sfIntRect){0, 0, 3840, 2704});

    all->dialogue_s[0].s = init_sprite("src/assets/img/dote.png",
    (sfVector2f){880, 230}, (sfIntRect){0, 0, 155, 60});
    all->dialogue_s[1].s = init_sprite("src/assets/img/math.png",
    (sfVector2f){0, 0}, (sfIntRect){0, 0, 1001, 210});
    all->dialogue_s[2].s = init_sprite("src/assets/img/math_end.png",
    (sfVector2f){0, 0}, (sfIntRect){0, 0, 1001, 210});
    all->dialogue_s[3].s = init_sprite("src/assets/img/toast.png",
    (sfVector2f){0, 0}, (sfIntRect){0, 0, 1001, 210});
    all->dialogue_s[4].s = init_sprite("src/assets/img/toast_end.png",
    (sfVector2f){0, 0}, (sfIntRect){0, 0, 1001, 210});

}

static void ini_quest(all_t *all)
{
    all->quest[0].s = init_sprite("src/assets/img/quest.png",
    (sfVector2f){3000, 3000}, (sfIntRect){0, 0, 307, 263});
    all->quest[1].s = init_sprite("src/assets/img/quest_end.png",
    (sfVector2f){0, 0}, (sfIntRect){0, 0, 1001, 210});
    all->quest[2].s = init_sprite("src/assets/img/quest_toast.png",
    (sfVector2f){0, 0}, (sfIntRect){0, 0, 1001, 210});
    all->quest[3].s = init_sprite("src/assets/img/quest_toast_end.png",
    (sfVector2f){0, 0}, (sfIntRect){0, 0, 1001, 210});
    all->quest[4].s = init_sprite("src/assets/img/icon.png",
    (sfVector2f){2450, 2290}, (sfIntRect){0, 0, 40, 40});
    for (int i = 0; i < VAR; i++)
        all->var[i] = 0;
    all->statue_s = 0;
    all->statue_t = 0;
    all->toast_s = 0;
    all->toast_t = 0;
    all->x = 1560;
}

static void init_all(all_t *all, char *name)
{
    sfVideoMode mode = {1920, 1080, 32};
    all->window = sfRenderWindow_create(mode, name,
    sfClose | sfResize, NULL);
    sfRenderWindow_setFramerateLimit(all->window, 60);
    all->music = sfMusic_createFromFile("src/assets/sounds/halo_theme.ogg");
    all->sound = sfSound_create();
    all->buffer = sfSoundBuffer_createFromFile("src/assets/sounds/click.ogg");
    all->state = MENU;
    all->pause = false;
    all->vol_m[0] = 2;
    all->nb_enemy = 1;
    all->vol_m[1] = 2;
    all->camera = sfView_createFromRect((sfFloatRect){0, 0, 1600, 800});
    all->mini_map = sfView_createFromRect((sfFloatRect){1600, 0, 200, 100});
    all->pos = (sfVector2i){0, 0};
    all->cmd = init_cmd(all->cmd);
    all->p = init_player(all->p);
}

all_t *init_struct(char *name)
{
    all_t *all = malloc(sizeof(all_t));

    all->cam_rect = (sfFloatRect){0, 0, 1600, 800};
    init_all(all, name);
    for (int i = 0; i < CLOCK; i++)
        all->clock[i] = sfClock_create();
    init_pause(all);
    init_menu(all);
    init_dialogue(all);
    init_ath(all);
    ini_quest(all);
    ini_pnj(all);
    all = init_all_hunter(all);
    all->inv = inventory(all->inv);
    all->p->health = 3;
    init_fight(all);
    sfSound_setBuffer(all->sound, all->buffer);
    sfSound_setVolume(all->sound, 2);
    return all;
}
