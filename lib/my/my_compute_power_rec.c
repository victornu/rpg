/*
** EPITECH PROJECT, 2021
** power rec
** File description:
** task04
*/

int my_compute_power_rec(int nb, int p);

int my_compute_power_rec(int nb, int p)
{
    if (p == 0)
        return (1);
    else
        return (nb * my_compute_power_rec(nb, p - 1));
}
