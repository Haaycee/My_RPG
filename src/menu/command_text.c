/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-alexis.arduca
** File description:
** cinematic
*/

#include "my.h"

char *fill_str(int command)
{
    char *str = malloc(sizeof(char) * 2);

    str[0] = command;
    str[1] = '\0';
    return (str);
}

char *str_key(int command)
{
    switch (command) {
    case 71:
        return ("KEY_LEFT");
    case 72:
        return ("KEY_RIGHT");
    case 73:
        return ("KEY_UP");
    case 74:
        return ("KEY_DOWN");
    }
    return ("SELECT ANOTHER KEY");
}

char *f_key2(int command)
{
    if (command == 93)
        return ("F9");
    if (command == 94)
        return ("F10");
    return ("F11");
}

char *f_key(int command)
{
    if (command == 85)
        return ("F1");
    if (command == 86)
        return ("F2");
    if (command == 87)
        return ("F3");
    if (command == 88)
        return ("F4");
    if (command == 89)
        return ("F5");
    if (command == 90)
        return ("F6");
    if (command == 91)
        return ("F7");
    if (command == 92)
        return ("F8");
    return (f_key2(command));
}

char *my_strcommands(int command)
{
    if (command >= 0 && command <= 25)
        return (fill_str(command + 65));
    if (command > 25 && command <= 35)
        return (fill_str(command + 22));
    if (command >= 71 && command <= 74)
        return (str_key(command));
    if (command >= 85 && command <= 99)
        return (f_key(command));
    return ("SELECT ANOTHER KEY");
}
