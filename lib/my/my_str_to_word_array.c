/*
** EPITECH PROJECT, 2022
** B-CPE-200-LIL-2-1-dante-thomas.wozniak
** File description:
** my_str_to word_array
*/

#include "../../include/my.h"

int it_is_alpha(char c, char cmpr)
{
    if (c == cmpr || c == '\0') {
        return 0;
    }
    return 1;
}

int my_stwa_next(char *str, int i, char c)
{
    while (it_is_alpha(str[i], c) == 0)
        i++;
    return i;
}

int count_words(char *str, char c)
{
    int nb = 0;

    for (int i = 0; str[i] != '\0';) {
        while (it_is_alpha(str[i], c) == 0) {
            if (str[i + 1] == '\0'){
                return nb;
            }
            i++;
        }
        nb++;
        while (it_is_alpha(str[i], c) == 1) {
            i++;
        }
    }
    return nb;
}

int *count_letters(char *str, char c)
{
    int *tab_words = malloc(sizeof(int) * count_words(str, c));
    int j = 0;

    for (int i = 0; str[i] != '\0';){
        while (it_is_alpha(str[i], c) == 0) {
            i++;
        }
        tab_words[j] = 0;
        while (it_is_alpha(str[i], c) == 1) {
            tab_words[j] += 1;
            i++;
        }
        j++;
    }
    return tab_words;
}

char **my_str_to_word_array(char *str, char c)
{
    char **array = malloc(sizeof(char *) * (count_words(str, c) + 1));
    int *tab_words = count_letters(str, c);
    int y = 0;
    int z = 0;
    int a = 0;
    for (int i = 0; str[i] != '\0';) {
        array[z] = malloc(sizeof(char) * tab_words[a] + 1);
        array[z][tab_words[a]] = '\0';
        a++;
        i = my_stwa_next(str, i, c);
        y = 0;
        while (it_is_alpha(str[i], c) == 1) {
            array[z][y] = str[i];
            i++;
            y++;
        }
        z++;
    }
    array[z] = 0;
    free(tab_words);
    return (array);
}
