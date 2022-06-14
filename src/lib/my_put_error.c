/*
** EPITECH PROJECT, 2021
** My_Putchar
** File description:
** Lib | My put error
*/

#include <unistd.h>

void my_putchar_error(char ch)
{
    write(2, &ch, 1);
}

int my_putstr_error(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar_error(str[i]);
        i = i + 1;
    }
    return (0);
}
