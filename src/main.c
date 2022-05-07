/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** main
*/

#include "../include/struct.h"

sfSprite *my_sprite(sfSprite *sprt, sfIntRect rct, sfVector2f pos, sfVector2f scl)
{
    sfSprite_setTextureRect(sprt, rct);
    sfSprite_setPosition(sprt, pos);
    sfSprite_setScale(sprt, scl);
    return sprt;
}

void movement_charactere_standing(game_t *game)
{
    my_printf("hello");
    game->scene->object[0].animation = (sfIntRect) {0, 0, 48, 64};
    game->scene->object[0].animation.left += 48;
    if (game->scene->object->animation.left > 240)
        game->scene->object[0].animation.left = 0;
}
void movement_charactere_running(game_t *game)
{

}
void movement_charactere_falling(game_t *game)
{

}

void animation_obj_one(game_t *game, int nb)
{
    game->scene->horloge->time = sfClock_getElapsedTime(game->scene->horloge[nb].clock);
    game->scene->horloge->seconds = game->scene->horloge[nb].time.microseconds / 10000;
    if (game->scene->horloge[nb].seconds > 1){
        movement_charactere_standing(game);
        sfSprite_setTextureRect(game->scene->object->sprite, game->scene->object->animation);
        sfClock_restart(game->scene->horloge[nb].clock);
    }
}

void initialize_obj_one(game_t *game, int nb)
{
    game->scene->object[nb].texture = sfTexture_createFromFile("./assets/sprites/characters/player.png", NULL);
    game->scene->object[nb].sprite = sfSprite_create();
    game->scene->object[nb].scale = (sfVector2f) {3, 3};
    game->scene->object[nb].position = (sfVector2f) {50, 50};
    game->scene->object[nb].animation = (sfIntRect) {0, 0, 48, 64};
    sfSprite_setTexture(game->scene->object[nb].sprite, game->scene->object[nb].texture, sfTrue);
    sfSprite_setTextureRect(game->scene->object[nb].sprite, game->scene->object[nb].animation);
    sfSprite_setPosition(game->scene->object[nb].sprite, game->scene->object[nb].position);
    sfSprite_setScale(game->scene->object[nb].sprite, game->scene->object[nb].scale);
}

void initialize_obj_two(game_t *game, int nb)
{
    game->scene->object[nb].texture = sfTexture_createFromFile("./assets/sprites/particles/dust_particles_01.png", NULL);
    game->scene->object[nb].sprite = sfSprite_create();
    game->scene->object[nb].scale = (sfVector2f) {3, 3};
    game->scene->object[nb].position = (sfVector2f) {60, 140};
    game->scene->object[nb].animation = (sfIntRect) {0, 0, 12, 12};
    sfSprite_setTexture(game->scene->object[nb].sprite, game->scene->object[nb].texture, sfTrue);
    sfSprite_setTextureRect(game->scene->object[nb].sprite, game->scene->object[nb].animation);
    sfSprite_setPosition(game->scene->object[nb].sprite, game->scene->object[nb].position);
    sfSprite_setScale(game->scene->object[nb].sprite, game->scene->object[nb].scale);
}

void initialize_timer_one(game_t *game, int nb)
{
    game->scene->horloge[nb].clock = sfClock_create();
}

void initialize_scene_one(game_t *game)
{
    game->scene = malloc(sizeof(scene_t) * 1);
    game->scene->object = malloc(sizeof(object_t) * 2);
    game->scene->horloge = malloc(sizeof(timer_t) * 2);
    initialize_obj_one(game, 0);
    initialize_timer_one(game, 0);
    initialize_obj_two(game, 1);
}

game_t *initialize_main(void)
{
    game_t *game = malloc(sizeof(game_t));

    game->mode.width = 1280;
    game->mode.height = 720;
    game->mode.bitsPerPixel = 32;
    initialize_scene_one(game);
    return game;
}

int draw_main(game_t *game)
{
    sfRenderWindow_clear(game->wdw, sfBlack);
    sfRenderWindow_drawSprite(game->wdw, game->scene->object->sprite, NULL);
    sfRenderWindow_drawSprite(game->wdw, game->scene->object[1].sprite, NULL);
    sfRenderWindow_display(game->wdw);
}


int events_main(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->wdw, &game->event)) {
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->wdw);
    }
}

int rpg(int ac, char **av)
{
    game_t *game = initialize_main(); 
    game->wdw = sfRenderWindow_create(game->mode, "my_rpg",
    sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(game->wdw, 60);
    while (sfRenderWindow_isOpen(game->wdw)){
        events_main(game);
        animation_obj_one(game, 0);
        draw_main(game);
    }
}

int main(int ac, char **av)
{
    rpg(ac, av);
    return 0;
}
