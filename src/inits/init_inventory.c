/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-alexis.arduca
** File description:
** init_inv
*/

#include "my.h"

inventory_t *inventory2(inventory_t *inv)
{
    int j = 0;

    for (int i = 0; i < OBJ; i++) {
        inv->obj_inv_s[i] = sfSprite_create();
        inv->obj_inv_t[i] = sfTexture_createFromFile
        ("src/assets/img/arme.png", sfFalse);
        sfSprite_setTexture(inv->obj_inv_s[i], inv->obj_inv_t[i], sfFalse);
        if (i < 5) {
            sfSprite_setPosition(inv->obj_inv_s[i],
            (sfVector2f){(80 * i + 20), 45});
        } else {
            sfSprite_setPosition(inv->obj_inv_s[i],
            (sfVector2f){(80 * j + 20), 125});
            j += 1;
        }
    }
    return (inv);
}

inventory_t *inventory(inventory_t *inv)
{
    inv = malloc(sizeof(inventory_t));

    inv->inv_s = sfSprite_create();
    inv->inv_t = sfTexture_createFromFile("src/assets/img/inv.png", sfFalse);
    for (int i = 0; i < 2; i++) {
        inv->slots_obj_s[i] = sfSprite_create();
        inv->slots_obj_t[i] =
        sfTexture_createFromFile("src/assets/img/inventory.png", sfFalse);
        sfSprite_setTexture(inv->slots_obj_s[i], inv->slots_obj_t[i], sfFalse);
        sfSprite_setPosition(inv->slots_obj_s[i],
        (sfVector2f){1700 + (i * 100), 50});
    }
    inv->inv_txt = sfText_create();
    sfSprite_setTexture(inv->inv_s, inv->inv_t, sfFalse);
    sfSprite_setPosition(inv->inv_s, (sfVector2f){0, 0});
    return (inventory2(inv));
}
