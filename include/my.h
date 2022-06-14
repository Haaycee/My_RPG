/*
** EPITECH PROJECT, 2021
** My.h
** File description:
** Best bro
*/

#ifndef _MY_H_
    #define _MY_H_
    #define UNUSED __attribute__((unused))
    #define MENU 1
    #define GAME 42
    #define SETTINGS 2
    #define HUNTER ((-1 * -(1 << 2)) * (-1))
    #define CINEMATIC 51
    #define PLAY_W 481
    #define PLAY_H 662
    #define SET_W 368
    #define SET_H 561
    #define EXIT_W 375
    #define EXIT_H 572
    #define ARR_W 152
    #define ARR_H 152
    #define BUTTONS_MENU 6
    #define VAR 20
    #define OBJ 10
    #define ENN 21
    #define JORDY 50
    #define CLOCK 6
    #define PARICULE_ANGLE_MIN (0)
    #define PARICULE_ANGLE_MAX (M_PI * 2)
    #define GRAVITY_X (1.0f * 0)
    #define GRAVITY_Y (1.0f * 0)
    #define ALPHA (1)
    #define PARICULE_MAX (10000)
    #define PARICULE_MAX_D (100)
    #define SPEED (1.0f)
    #include <stdarg.h>
    #include <stdio.h>
    #include <string.h>
    #include <unistd.h>
    #include <time.h>
    #include "math.h"
    #include <stdlib.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <sys/wait.h>
    #include <fcntl.h>
    #include <dirent.h>
    #include <stdbool.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/Audio/Export.h>
    #include <SFML/Audio/SoundStatus.h>
    #include <SFML/Audio/Types.h>
    #include <SFML/System/InputStream.h>
    #include <SFML/System/Time.h>
    #include <SFML/Graphics/View.h>
    #include "criterion/criterion.h"
    #include "criterion/redirect.h"

//? Struct

typedef struct inventory_s {
    sfSprite *slots_obj_s[2];
    sfTexture *slots_obj_t[2];
    sfSprite *inv_s;
    sfTexture *inv_t;
    sfSprite *obj_inv_s[OBJ];
    sfTexture *obj_inv_t[OBJ];
    sfText *inv_txt;
    sfVector2f *pos_inv;
    sfVector2f world_inv;
} inventory_t;

typedef struct sprite_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
    sfIntRect rect;
    int offset;
    int x;
} sprite_t;

typedef struct button_s {
    sprite_t *s;
    bool is_clickable;
    bool is_clicked;
    bool is_hover;
} button_t;

typedef struct menu_s {
    button_t btn[BUTTONS_MENU];
    sprite_t spr[5];
} menu_t;

typedef struct command_s {
    int up;
    int left;
    int right;
    int down;
    int attack;
    int inv;
    int obj[2];
    sfText *up_txt;
    sfText *down_txt;
    sfText *right_txt;
    sfText *left_txt;
    sfText *attack_txt;
    sfText *inv_txt;
    sfText *obj_txt[2];
    sfText *up_text;
    sfText *down_text;
    sfText *right_text;
    sfText *left_text;
    sfText *inv_text;
    sfText *attack_text;
    sfText *obj_text[2];
    sfText *text;
    sfFont *font;
} command_t;

typedef struct pnj_s {
    sfSprite *villager;
    int VillagerX;
    int VillagerY;
} pnj_t;

typedef struct play_s {
    int g;
    sfIntRect rect;
    sfIntRect rectlife;
} play_t;

typedef struct player_s {
    sfSprite *my_player;
    sfTexture *my_player2;
    sfIntRect rect_p;
    sfIntRect rect_p2;
    sfText *lvl;
    int x;
    int y;
    int PersoX;
    int PersoY;
    int g;
    int health;
    int exp;
    int level;
    int strength;
} player_t;

typedef struct ennemy_s {
    sfSprite *enemy_s;
    sfTexture *enemy_t;
    sfIntRect rect;
    int EnnemieX;
    int EnnemieY;
    int boss_health;
    int ennemy_health;
    int health;
    int strenght;
    int level;
} ennemy_t;

typedef struct fight_s {
    player_t *p;
    ennemy_t *enemy;
    sfSprite *player;
    sfSprite *opponent;
    sfSprite *fight_s;
    sfTexture *fight_t;
    sfSprite *menu_fight_s;
    sfTexture *menu_fight_t;
    sfSprite *menu_atq_s;
    sfTexture *menu_atq_t;
    sfSprite *life1_s;
    sfSprite *life2_s;
    sfSprite *fire_s;
    sfTexture *fire_t;
    sfTexture *life1_t;
    sfTexture *life2_t;
    sfSprite *slash_s;
    sfTexture *slash_t;
    sfSprite *shoot_s;
    sfTexture *shoot_t;
    sfVector2f pos_p;
    sfVector2f pos_f;
    sfVector2f pos_s;
    sfIntRect rect_f;
    sfIntRect rect_slash;
    sfText *atq_sw;
    sfText *atq_pi;
    sfText *shield;
    int x;
    int g;
    int turn;
} fight_t;

typedef struct hunter_s {
    sprite_t *hunter_s;
    sfVector2f pos;
    int speed;
    sfSound *mos_sound;
} hunter_t;

typedef struct particle_s {
    sfVector2f pos;
    sfVector2f vel;
    sfColor color;
    size_t radius;
    bool living;
} particle_t;

typedef struct particle_environment_s {
    float angle_min;
    float angle_max;
    float speed;
    sfVector2f gravity;
    sfUint8 alpha;
    sfClock *clock;
    sfCircleShape *circle_shape;
} particle_environment_t;

typedef struct screen_s {
    sfRenderWindow *window;
    sfEvent event;
    sfVector2i pos;
    sfKeyCode key;
    particle_t particle[PARICULE_MAX];
    particle_environment_t particle_environment;
} screen_t;

typedef struct all_s {
    sfRenderWindow *window;
    sfEvent event;
    sfClock *clock[CLOCK];
    sfTime time[CLOCK];
    sfMusic *music;
    sfSound *sound;
    sfSoundBuffer *buffer;
    sprite_t *game;
    sprite_t layer[2];
    menu_t *menu;
    command_t *cmd;
    player_t *p;
    inventory_t *inv;
    screen_t *screen;
    fight_t *fight;
    ennemy_t *ennemy[ENN];
    sprite_t *background_hunter;
    sfSoundBuffer *buffer_h;
    hunter_t hunter[JORDY];
    button_t cinematic[10];
    button_t pause_s[5];
    button_t dialogue_s[5];
    button_t quest[5];
    button_t ath[5];
    button_t location[3];
    button_t pnj[3];
    sfView *camera;
    sfView *mini_map;
    sfVector2i pos;
    sfVector2f worldPos;
    sfVector2f worldMousePos;
    sfFloatRect cam_rect;
    char **colissions;
    int state;
    int vol_m[2];
    int var[VAR];
    int statue_s;
    int statue_t;
    int toast_s;
    int toast_t;
    int x;
    int lifes;
    int nb_enemy;
    int **map;
    int map_width;
    int nb_sprites;
    int map_height;
    float seconds[CLOCK];
    bool pause;
    bool can_launch;
} all_t;

//? Lib
int my_printf(char *str, ...);
int count_percentage(char *str);
int my_getnbr(char const *str);
int my_put_nbr(int nb);
void my_putchar(char ch);
int my_putstr(char const *str);
int my_strlen(char const *str);
char *my_revstr(char *str);
char *my_strcat(char *dest, char const *src);
char *my_strcat2(char *dest, char const *src);
int my_strcmp(char *str, char *env);
void my_print_2d(char **tab);
int strrlen(char **env);
int my_strlen_nbr(char const *str);
int my_str_is_alpha(char *str);
int my_str_isnum(char *str);
int my_ch_is_alpha(char ch);
int verify_is_alpha(char *str, int i);
int my_str_isprintable(char *str);
int free_a_lot_of_function(char *nb, ...);
int free_array(char **tab);
char **malloc_2d_array(unsigned long nb_rows, unsigned long nb_cols);
int count_elem(char *str, char elem);
char **my_word_array(char *str, char sep);
void my_putchar_error(char ch);
int my_putstr_error(char const *str);
void my_print_2d_other(const char **tab);
int my_put_nbr_neg(int nb);
int print_arg_d(int stock);
int print_arg_c(int stock);
char *open_read(char *files);
int print_arg_s(char *str, char *stock, int i);
int print_arg_percentage(void);
char *transform_buffer(char *entry, char *buffer);
int operator(char const *str);
char *my_strndup(char const *src, int n);
int len_2d_array(char **array);
int free_2d_array(char **array);
int my_atoi(char *str);
void *my_calloc(unsigned long size);
char *int_to_char(int nb);

//? Utils
void my_putchar(char ch);
char *my_revstr(char *str);
char *my_itoa(char *d, int n);
int len_before_char(char *str, char c);
int is_on(sfVector2i mouse, sfVector2f button, int height, int width);

//? Inits
void init_ath(all_t *all);
void init_menu(all_t *all);
void destroy_all(all_t *all);
int initiate_game(all_t *all, char *name, char **av);
void detect_dialogue(all_t *all);
all_t *init_struct(char *name);
sprite_t *init_sprite(char *pathname, sfVector2f pos, sfIntRect rect);
player_t *init_player(player_t *p);
command_t *init_cmd(command_t *cmd);
sfText *init_text(command_t *cmd, char *text, sfVector2f pos, int size);
inventory_t *inventory(inventory_t *inv);
void init_fight(all_t *all);
void init_ennemy(all_t *all, int i, char *path, sfVector2f pos);
void ini_pnj(all_t *all);
void init_ennemy2(all_t *all, int i, char *path, sfVector2f pos);

//? Map
char **map_parser(char *str);
int generate_map(char *str, all_t *all);
int generate_sprites_map(all_t *all);
int generate_colissions(char *str, all_t *all);
int check_collision(all_t *all, int x, int y);
void zoom(all_t *all);

//? Game
void game(all_t *all);
void camera_player(all_t *all, sfVector2f sprite);
void buttons_pause(all_t *all);
void pause_draw(all_t *all);
int game_loop(all_t *all);
void player_moovement(all_t *all);
void main_inv(all_t *all);
void inventory_rechange(all_t *all, int x);
void pause_position(all_t *all);
void camera_top_left(all_t *all);
void camera_bot_left(all_t *all);
void camera_top_right(all_t *all);
void camera_bot_right(all_t *all);
void camera_player_top(all_t *all, int x);
void dialogue_mathematician(all_t *all);
void dialogue_toast(all_t *all);
void change_texture(all_t *all, char *filename);

//? Hunter
void hunter(all_t *all);
all_t *init_all_hunter(all_t *all);

//? Menu
void menu(all_t *all);
void settings(all_t *all);
void menu_quit(all_t *all);
void draw_curseur(all_t *all, int i, int j);
void leave_menu(all_t *all);
void detect_click(all_t *all, int i, int j);
sfText *init_font(char command, sfVector2f v, int x, command_t *cmd);
char *my_strcommands(int command);
void click_cmd(all_t *all);
void good_cmd(int var, all_t *all, int cmd);
void command_edit_menu(all_t *all);
void buttons(all_t *all);
void event_buttons(all_t *all);

//? Tests
void redirect_all_std(void);

//? cinematic
void cinematic(all_t *all);
void init_cinematic(all_t *all);

//? Particles
void init_particle_environment(particle_environment_t *particle_environment,
const sfVector2f angle, const sfVector2f gravity, const sfUint8 alpha);
void init_particle(const particle_environment_t *particle_environment,
particle_t *particule, const sfVector2f pos);
void display_particle(all_t *all, const particle_t *particule,
sfCircleShape *circle_shape);
void update_particle(const particle_environment_t *particle_environment,
particle_t *particule);
void add_particle(const particle_environment_t *particle_environment,
particle_t *particule, const size_t particle_num, const sfVector2f pos);
int show_particles(all_t *all);
void display_window(all_t *all);
void manage_key_window(all_t *all);
void init_particle_environment(particle_environment_t *particle_environment,
const sfVector2f angle, const sfVector2f gravity, const sfUint8 alpha);
void particle_conditions(const particle_environment_t *particle_environment,
particle_t *particule, const size_t particle_num, const sfVector2f pos);
void particle_conditions_r(const particle_environment_t *particle_environment,
particle_t *particule, const size_t particle_num, const sfVector2f pos);
int show_particles_r(all_t *all);
void display_window_r(all_t *all);
void manage_key_window_r(all_t *all);
void update_particle_r(const particle_environment_t *particle_environment,
particle_t *particule);
void display_particle_r(all_t *all, const particle_t *particule,
sfCircleShape *circle_shape);
void init_particle_r(const particle_environment_t *particle_environment,
particle_t *particule, const sfVector2f pos);
void init_particle_environment_r(particle_environment_t *particle_environment,
const sfVector2f angle, const sfVector2f gravity, const sfUint8 alpha);
void add_particle_r(const particle_environment_t *particle_environment,
particle_t *particule, const size_t particle_num, const sfVector2f pos);

//? Battle
void fight_display(all_t *all, ennemy_t *ennemy);
void menu_attack(all_t *all);
void menu_inv(all_t *all);
void leave(all_t *all);
void boss_attack(all_t *all);
void player_attack_battle(all_t *all, ennemy_t *ennemy);
void slash_anim(all_t *all, ennemy_t *enn);
void sword_attack(all_t *all, ennemy_t *enn);
void shoot_attack(all_t *all, ennemy_t *enn);
void shield(all_t *all);
void boss_spawning(all_t *all);
void ennemies_spawning(all_t *all);
void detect_adv(all_t *all, player_t *player, ennemy_t *ennemy, int i);
void death_reset(all_t *all);

//? Destroy
void destroy_inv(inventory_t *inv);
void destroy_cmd(command_t *cmd);
void destroy_menu(all_t *all);

#endif/* !MY_H_ */
