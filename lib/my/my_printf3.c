/*
** EPITECH PROJECT, 2021
** B-PSU-100-LIL-1-1-myprintf-victor.braun
** File description:
** my_printf3
*/

#include "../../include/my.h"

void pointer_p(unsigned long long int nb)
{
    my_putchar('0');
    my_putchar('x');
}

void hexa_xp(unsigned long long int nb)
{
    char *save_numb = malloc(sizeof(char) * 25);
    for (int i = 0; nb > 0; i++) {
        save_numb[i] = HEXA_MAJ[nb % 16];
        nb = nb / 16;
    }
    my_revstr(save_numb);
    my_putstr(save_numb);
    free(save_numb);
}

void binary_b(unsigned int nb)
{
    unsigned int result;

    while (nb != 0) {
        result = nb % 2;
        nb = nb / 2;
        my_put_nbru(result);
    }
}
