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
    #include "file.h"
    #include "my.h"

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
    sfIntRect animation;
}object_t;

typedef struct button_s {
    //...
}button_t;

typedef struct scene_s {
    object_t *object;
    button_t *button;
    horloge_t *horloge;
}scene_t;

typedef struct game_s {
    sfRenderWindow *wdw;
    sfVideoMode mode;
    sfEvent event;
    scene_t *scene;
}game_t;

#endif
