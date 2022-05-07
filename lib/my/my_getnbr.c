/*
** EPITECH PROJECT, 2021
** my_swap.c
** File description:
** emacs
*/

int my_getnbr(char const *str)
{
    int number = 0;
    int sign = 1;

    if (*str == '-') {
        sign = -sign;
        str++;
    }
    while (*str >= '0' && *str <= '9') {
        number = number * 10;
        number = number + *str - '0';
        str++;
    }
    return (number * sign);
}
