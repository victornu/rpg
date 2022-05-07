/*
** EPITECH PROJECT, 2021
** B-PSU-100-LIL-1-1-myprintf-victor.braun
** File description:
** main
*/

#include "../../include/my.h"

char *my_printf(char *str, ...)
{
    int i = 0;
    va_list ap;

    va_start(ap, str);
    while (str[i] != '\0') {
        if (str[i] == '%') {
            i++;
            check_letter(i, str, ap);
        } else
            my_putchar(str[i]);
        i++;
    }
    va_end(ap);
    return (str);
}

void flag_base(char s, va_list list)
{
    if (s == 'b')
        binary_b(va_arg(list, unsigned int));
    if (s == 'o')
        octal_o(va_arg(list, unsigned int));
    if (s == 'x')
        hexa_min(va_arg(list, unsigned int));
    if (s == 'X')
        hexa_maj(va_arg(list, unsigned int));
    if (s == 'S')
        string_s(va_arg(list, char *));
    if (s == '%')
        my_putchar('%');
}

void flag_classic(char s, va_list list)
{
    if (s == 'c')
        my_putchar(va_arg(list, int));
    if (s == 's')
        my_putstr(va_arg(list, char *));
    if (s == 'd' || s == 'i')
        my_put_nbr(va_arg(list, int));
    if (s == 'u')
        my_put_nbru(va_arg(list, unsigned int));
    if (s == 'p') {
        unsigned long long int nombre;
        nombre = va_arg(list, unsigned long long int);
        pointer_p(nombre);
        hexa_xp(nombre);
    }
}

void check_letter(int i, char *str, va_list ap)
{
    char *flag = "sdicubxXoSp%";
    for (int j = 0; flag[j] != '\0'; j++) {
        if (str[i] == flag[j]) {
            flag_base(str[i], ap);
            flag_classic(str[i], ap);
        }
    }
}
