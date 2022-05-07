/*
** EPITECH PROJECT, 2021
** my_swap.c
** File description:
** emacs
*/

void my_putchar(char c);

void my_putstr(char const *str);

void my_putstr(char const *str)
{
    int i;

    i = 0;
    while (str[i] != '\0') {
        my_putchar(str[i]);
        i = i + 1;
    }
}
