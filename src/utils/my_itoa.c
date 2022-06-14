/*
** EPITECH PROJECT, 2021
** B-MUL-100-MPL-1-1-myrunner-hades.cuisinier
** File description:
** my_itoa
*/

char *my_revstr(char *str);

char *my_itoa(char *d, int n)
{
    int i = 0;
    int minus = n >= 0 ? 0 : 1;

    if (minus || n == 0) {
        d[i] = -(n % 10) + '0';
        n = -(n / 10);
        i++;
    }
    while (n) {
        d[i] = n % 10 + '0';
        n /= 10;
        i++;
    }
    if (minus) {
        d[i] = '-';
        i++;
    }
    d[i] = 0;
    return my_revstr(d);
}
