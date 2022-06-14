/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-alexis.arduca
** File description:
** collisions
*/

#include "my.h"

int check_collision(all_t *all, int x, int y)
{
    if (x < 0 || x >= all->map_width || y < 0 || y >= all->map_height)
        return 1;
    if (all->colissions[y][x] == '1')
        return 1;
    return 0;
}

static void alloc_init_variables(all_t *all, char *buffer)
{
    all->map_height = count_elem(buffer, '\n');
    all->map_width = len_before_char(buffer, '\n');
    all->colissions = malloc(sizeof(char *) * (all->map_height + 1));
    for (int i = 0; i < all->map_height; i++)
        all->colissions[i] = my_calloc(sizeof(char) * (all->map_width + 1));
    all->colissions[all->map_height] = 0;
}

int generate_colissions(char *str, all_t *all)
{
    char *buffer = open_read(str);
    int i = 0;
    int j = 0;
    int k = 0;

    alloc_init_variables(all, buffer);
    while (i < all->map_height) {
        if (buffer[j] == '\n') {
            all->colissions[i][k] = '\0';
            i++;
            j++;
            k = 0;
            continue;
        }
        all->colissions[i][k++] = buffer[j];
        j++;
    }
    free(buffer);
    return 0;
}
