/*
** EPITECH PROJECT, 2021
** my_str_to_word_array.c
** File description:
** emacs
*/

int my_str_isalpha(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] > 0 && str[i] < 65) {
            return (0);
        }
        if (str[i] < 97 && str[i] > 90) {
            return (0);
        }
        if (str[i] < 127 && str[i] > 122) {
            return (0);
        }
    }
    return (1);
}
