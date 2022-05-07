/*
** EPITECH PROJECT, 2021
** my_put_nbr
** File description:
** yes
*/

#include <stdlib.h>
#include <string.h>

char *my_strcat(char *dest, char const *src);
int my_putnbr_money(int nb, char *str);

void addend(char *str, char c)
{
    char tmp[2] = {c, 0};

    my_strcat(str, tmp);
}

int print_nbr(int nb, char *str)
{
    int i = 0;
    if (nb >= 0) {
        if (nb >= 10) {
            i = (nb % 10);
            nb = (nb - i) / 10;
            my_putnbr_money(nb, str);
            addend(str, i + '0');
        } else {
            addend(str, nb % 10 + '0');
        }
    }
}

int my_putnbr_money(int nb, char *str)
{
    print_nbr(nb, str);
    return (0);
}
