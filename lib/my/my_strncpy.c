/*
** EPITECH PROJECT, 2021
** char * my_strncpy ( char * dest , char const * src , int n ) ;
** File description:
** emacs
*/

int main(void);

void my_putchar(char c);

void my_putstr(char const *str);

char *my_strncpy(char *dest, char const *src, int n);

char *my_strncpy(char *dest, char const *src, int n)
{
    int c = 0;

    while (dest[c] != '\0' && c < n) {
        dest[c] = src[c];
        c = c + 1;
    }
    dest[c] = '\0';
    return (dest);
}
