/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-mydefender-hades.cuisinier
** File description:
** is_on
*/

#include "my.h"

int is_on(sfVector2i mouse, sfVector2f button, int height, int width)
{
    if (mouse.x >= button.x && mouse.x <= button.x + width)
        if (mouse.y >= button.y && mouse.y <= button.y + height)
            return 1;
    return 0;
}
