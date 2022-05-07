/*
** EPITECH PROJECT, 2021
** B-PSU-100-LIL-1-1-myls-victor.braun
** File description:
** my_strdup
*/

#include "../../include/my.h"

char *my_strdup(char const *src)
{
    char *dest;

    dest = malloc(sizeof(char) * (my_strlen(src) + 1));
    dest = my_strcpy(dest, src);
    return (dest);
}
