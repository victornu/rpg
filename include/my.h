/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** prototype of all of my functions present in libmy.a
*/

#ifndef MY_H_
    #define MY_H_
    #define HEXA_MAJ "0123456789ABCDEF"
    #define HEXA_MIN "0123456789abcdef"
    #define OCTA "01234567"

    #include <stdlib.h>
    #include <stdarg.h>

void my_putchar(char c);
char *my_strstr(char *str, char const *to_find);
int my_isneg(int nb);
int my_strcmp(char const *s1, char const *s2);
int my_put_nbr(int nb);
int my_strncmp(char const *s1, char const *s2, int n);
void my_swap(int *a, int *b);
char *my_strupcase(char *str);
int my_putstr(char const *str);
char *my_strlowcase(char *str);
char *my_strlowercase(char *str);
int my_strlen(char const *str);
char *my_strcapitalize(char *str);
int my_getnbr(char const *str);
int my_str_isalpha(char const *str);
void my_sort_array(int *tab, int size);
void my_sort_int_array(int *tab, int size);
int my_str_isnum(char const *str);
int my_compute_power_rec(int nb, int power);
int my_str_islower(char const *str);
int my_compute_square_root(int nb);
int my_str_isupper(char const *str);
int my_is_prime(int nb);
int my_str_isprintable(char const *str);
int my_find_prime_sup(int nb);
int find_primesup(int nb);
int my_showstr(char const *str);
char *my_strcpy(char *dest, char const *src);
int my_showmem(char const *str, int size);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strcat(char *dest, char const *src);
void my_revstr(char *str);
char *my_strncat(char *dest, char const *src, int nb);
int my_count_words(char const *str);
int my_isalpha(char c);
int my_isalphanum(char const c);
int my_ischar(char const c);
int my_isnbr(char const c);
char *my_strdup(char const *src);
int my_atoi(char *str);
void replace(char *str, va_list ap);
char *my_printf(char *format, ...);
void binary_b(unsigned int nb);
void hexa_min(int nb);
void hexa_maj(int nb);
void octal_o(int nb);
void string_s(char *str);
void pointer_p(unsigned long long int nb);
void hexa_xp(unsigned long long int nb);
void check_letter(int i, char *str, va_list ap);
char *transform_arr(char *str);
void str_word_array(char *str);
char *skip_number(char *str);
int change_int(char str);
int count_height(char *str);
void function_square(int **array_map, int height, int width);
int my_put_nbru(unsigned int nb);
int my_putnbr_money(int nb, char *str);
char **my_str_to_word_array(char *str, char c);

char *load_file_in_mem(char const *filepath);
#endif
