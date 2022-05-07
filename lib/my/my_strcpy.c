/*
** EPITECH PROJECT, 2021
** emacs
** File description:
** trysomething
*/

int main(void);

void my_putchar(char c);

void my_putstr(char const *str);

char *my_strcpy(char *dest, char const *src);

char *my_strcpy(char *dest, char const *src)
{
    int c = 0;

    while (dest[c] != '\0' && src[c] != '\0') {
        dest[c] = src[c];
        c = c + 1;
    }
    dest[c] = '\0';
    return (dest);
}
