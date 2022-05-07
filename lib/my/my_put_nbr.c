/*
** EPITECH PROJECT, 2021
** step1
** File description:
** rush
*/

#include "../../include/my.h"

int my_put_nbr(int nb)
{
    if (nb > 2147483647 || nb < -2147483647) {
        my_putchar('0');
    }

    if (nb >= 0 && nb <= 9) {
        my_putchar(nb + 48);
    }

    if (nb > 9) {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    }
    return 0;
}

int my_put_nbru(unsigned int nb)
{
    if (nb >= 0 && nb <= 9) {
        my_putchar(nb + 48);
    }

    if (nb > 9) {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    }
    return 0;
}
