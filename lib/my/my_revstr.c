/*
** EPITECH PROJECT, 2021
** char * my_revstr ( char * str )
** File description:
** char * my_revstr ( char * str )
*/

int main(void);

void my_putchar(char c);

void my_putstr(char const *str);

char *my_revstr(char *str)
{
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    i--;
    for (int a = 0; a <= i; i--, a++) {
        char swap;
        swap = str[a];
        str[a] = str[i];
        str[i] = swap;
    }
    return (str);
}
