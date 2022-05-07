/*
** EPITECH PROJECT, 2021
** my_swap.c
** File description:
** emacs
*/

void my_swap(int *a, int *b);

void my_swap(int *a, int *b)
{
    int swap;

    swap = a[0];
    a[0] = b[0];
    b[0] = swap;
}
