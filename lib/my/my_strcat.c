/*
** EPITECH PROJECT, 2021
** my_swap.c
** File description:
** emacs
*/

char *my_putstr(char *str);

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int x = 0;
    while (dest[i] != '\0') {
        i++;
    }
    while (src[x] != '\0') {
        dest[i] = src[x];
        i = i + 1;
        x = x + 1;
    }
}
