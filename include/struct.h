/*
** EPITECH PROJECT, 2021
** B-MUL-100-LIL-1-1-myrunner-victor.braun
** File description:
** struc
*/

#ifndef STRUC_H_
    #define STRUC_H_

    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Window.h>
    #include <SFML/Audio.h>
    #include <stdlib.h>
    #include <fcntl.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <math.h>

typedef struct stat_s {
    int stat;
}stat_t;

typedef struct horloge_s {
    sfClock *clock;
    sfTime time;
    float seconds;
}horloge_t;

typedef struct object_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f scale;
    sfVector2f position;
    sfVector2f position_hitbox;
    sfIntRect animation;
    sfRectangleShape *rect;
    sfIntRect hitbox;
    stat_t stat;
}object_t;

typedef struct object_map_s {
    sfSprite **sprite;
    sfTexture **texture;
    sfVector2f scale;
    sfVector2f position;
    sfIntRect *animation;
    sfRectangleShape **rect;
    int **rectangle;
    char *str;
}object_map_t;

typedef struct button_s {
    //...
}button_t;

typedef struct scene_s {
    object_t *object;
    object_map_t *object_map;
    button_t *button;
    horloge_t *horloge;
    sfRectangleShape *rect;
}scene_t;

typedef struct menu_s {
    int menu;
    sfSprite *back;
    sfTexture *text;
    sfSprite *play;
    sfTexture *textp;
    sfSprite *option;
    sfTexture *texto;
    sfSprite *quit;
    sfTexture *textq;
    sfSprite *main;
    sfTexture *textm;
    sfSprite *htp;
    sfTexture *texth;
    sfSprite *game;
    sfTexture *textg;
}menu_t;

typedef struct game_s {
    sfRenderWindow *wdw;
    sfVideoMode mode;
    sfEvent event;
    sfView *view;
    scene_t *scene;
    menu_t *menu;
}game_t;

#endif
