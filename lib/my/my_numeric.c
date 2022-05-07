/*
** EPITECH PROJECT, 2021
** my_str_to_word_array.c
** File description:
** emacs
*/

int my_numeric(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] > 0 && str[i] < 48) {
            return 0;
        }
        if (str[i] > 57 && str[i] < 65) {
            return 0;
        }
        if (str[i] > 90 && str[i] < 97) {
            return 0;
        }
        if (str[i] > 122 && str[i] < 127) {
            return 0;
        }
    }
    return (1);
}
