/*
** EPITECH PROJECT, 2021
** My_Putchar
** File description:
** Lib | Putchar
*/

#include <unistd.h>

void my_putchar(char ch)
{
    write(1, &ch, 1);
}
