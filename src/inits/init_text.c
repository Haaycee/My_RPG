/*
** EPITECH PROJECT, 2022
** B-MUL-100-MPL-1-1-myrunner-hades.cuisinier
** File description:
** init_text
*/

#include "my.h"

sfText *init_text(command_t *cmd, char *line, sfVector2f pos, int size)
{
    sfText *text = sfText_create();

    sfText_setPosition(text, pos);
    sfText_setString(text, line);
    sfText_setFont(text, cmd->font);
    sfText_setCharacterSize(text, size);
    sfText_setColor(text, sfBlack);
    return (text);
}

sfText *init_font(char command, sfVector2f v, int x, command_t *cmd)
{
    char *to_print = my_strcommands(command);
    sfVector2f vectext;
    sfText *text = sfText_create();

    vectext.x = v.x + x + 20;
    vectext.y = v.y;
    sfText_setPosition(text, vectext);
    sfText_setString(text, to_print);
    sfText_setFont(text, cmd->font);
    sfText_setCharacterSize(text, 30);
    sfText_setColor(text, sfRed);
    return (text);
}
