/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-alexis.arduca
** File description:
** parser
*/

#include "my.h"

char *open_read(char *files)
{
    long int size = 40729;
    int fd = open(files, O_RDONLY);
    char *buffer = malloc(sizeof(char) * (size + 1));

    if (fd == -1)
        return (NULL);
    read(fd, buffer, size);
    buffer[size] = '\0';
    return (buffer);
}

static int get_size(char *str, char end)
{
    int i = 0;

    while (str[i] != end && str[i])
        i++;
    return i;
}

char **map_parser(char *str)
{
    char **array = NULL;
    int size = count_elem(str, '\n');
    int shifter = 0;
    array = malloc(sizeof(char *) * (size + 1));

    for (int i = 0; i < size; i++) {
        array[i] = my_strndup(str + shifter, get_size(str+shifter, '\n'));
        shifter += get_size(str+shifter, '\n') + 1;
    }
    array[size] = NULL;
    return array;
}

int generate_map(char *str, all_t *all)
{
    char **tmp = NULL;
    char **array = NULL;
    char *buffer = open_read(str);

    all->map = malloc(sizeof(int *) * (count_elem(buffer, '\n') + 1));
    all->map_height = count_elem(buffer, '\n');
    all->map_width = 0;
    array = map_parser(buffer);
    for (int i = 0; array[i]; i++) {
        tmp = my_word_array(array[i], ',');
        all->map[i] = malloc(sizeof(int) * (len_2d_array(tmp) + 1));
        all->map_width = all->map_width ? all->map_width : len_2d_array(tmp);
        for (int j = 0; tmp[j]; j++)
            all->map[i][j] = my_atoi(tmp[j]);
        free_2d_array(tmp);
        tmp = NULL;
    }
    free(buffer);
    free_2d_array(array);
    return 0;
}
