/*
** EPITECH PROJECT, 2021
** B-PSU-100-LIL-1-1-myprintf-victor.braun
** File description:
** hexa
*/

#include "../../include/my.h"

void hexa_min(int nb)
{
    char *save_numb = malloc(sizeof(char) * 100);
    for (int i = 0; nb > 0; i++) {
        save_numb[i] = HEXA_MIN[nb % 16];
        nb = nb / 16;
    }
    my_revstr(save_numb);
    my_putstr(save_numb);
}

void hexa_maj(int nb)
{
    char *save_numb = malloc(sizeof(char) * 100);
    for (int i = 0; nb > 0; i++) {
        save_numb[i] = HEXA_MAJ[nb % 16];
        nb = nb / 16;
    }
    my_revstr(save_numb);
    my_putstr(save_numb);
}

void octal_o(int nb)
{
    char *save_numb = malloc(sizeof(char) * 100);
    for (int i = 0; nb > 0; i++) {
        save_numb[i] = OCTA[nb % 8];
        nb = nb / 8;
    }
    my_revstr(save_numb);
    my_putstr(save_numb);
}

void string_s(char *str)
{
    int nb;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 32 || str[i] >= 127) {
            nb = str[i];
            my_putchar('\\');
            octal_o(nb);
        } else
            my_putchar(str[i]);
    }
}
