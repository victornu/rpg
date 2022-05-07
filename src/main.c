/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** main
*/

#include "../include/struct.h"

void movements_particul(game_t *game)
{
    game->scene->object[1].animation.left += 24;
    if (game->scene->object[1].animation.left >= 36)
        game->scene->object[1].animation.left = 0;
    sfSprite_setTextureRect(game->scene->object[1].sprite, game->scene->object[1].animation);
}

void movement_charactere_standing(game_t *game)
{
    if (game->scene->object->animation.top != 16){
        game->scene->object[0].animation.top = 16;
        game->scene->object[0].animation.left = 0;
    }
    game->scene->object[0].animation.left += 48;
    if (game->scene->object->animation.left > 240)
        game->scene->object[0].animation.left = 0;
}

void movement_charactere_running(game_t *game)
{
    if (game->scene->object->animation.top != 64){
        game->scene->object[0].animation.left = 0;
        game->scene->object[0].animation.top = 64;
    }
    game->scene->object[0].animation.left += 48;
    if (game->scene->object->animation.left > 240){
        game->scene->object[0].animation.left = 0;
    }
}

void movement_charactere_hitting(game_t *game)
{
    if (game->scene->object->animation.top != 112){
        game->scene->object[0].animation.top = 112;
        game->scene->object[0].animation.left = 0;
    }
    game->scene->object[0].animation.left += 48;
    if (game->scene->object->animation.left > 144){
        game->scene->object[0].animation.left = 0;
        game->scene->object->stat.stat = 1;
        }
} 

void movement_charactere_falling(game_t *game)
{
    if (game->scene->object->animation.top != 208)
        game->scene->object[0].animation.top = 208;
    game->scene->object[0].animation.left += 48;
    if (game->scene->object->animation.left > 96){
        game->scene->object[0].animation.left = 0;
    }
}

void movement_charactere(game_t *game, int mode)
{
    if (mode == 1)
        movement_charactere_standing(game);
    if (mode == 2)
        movement_charactere_running(game);
    if (mode == 3)
        movement_charactere_hitting(game);
    if (mode == 4)
        movement_charactere_falling(game);
    sfSprite_setTextureRect(game->scene->object[0].sprite, game->scene->object[0].animation);
}

void animation_charactere(game_t *game, int mode)
{
    game->scene->horloge->time = sfClock_getElapsedTime(game->scene->horloge->clock);
    game->scene->horloge->seconds = game->scene->horloge->time.microseconds / 10000;
    if (game->scene->horloge->seconds > 9){
        movement_charactere(game, mode);
        movements_particul(game);
        sfClock_restart(game->scene->horloge->clock);
    }
}

void initialize_obj_charactere_stat(game_t *game, int nb, int scene)
{
    game->scene[scene].object->stat.stat = 1;
}

void initialize_obj_charactere(game_t *game, int nb, int scene)
{
    game->scene[scene].object[nb].texture = sfTexture_createFromFile("./assets/sprites/characters/player.png", NULL);
    game->scene[scene].object[nb].sprite = sfSprite_create();
    game->scene[scene].object[nb].scale = (sfVector2f) {3.4, 3.4};
    game->scene[scene].object[nb].position = (sfVector2f) {50, 50};
    game->scene[scene].object[nb].animation = (sfIntRect) {0, 16, 48, 32};
    sfSprite_setTexture(game->scene[scene].object[nb].sprite, game->scene[scene].object[nb].texture, sfTrue);
    sfSprite_setTextureRect(game->scene[scene].object[nb].sprite, game->scene[scene].object[nb].animation);
    sfSprite_setPosition(game->scene[scene].object[nb].sprite, game->scene[scene].object[nb].position);
    sfSprite_setScale(game->scene[scene].object[nb].sprite, game->scene[scene].object[nb].scale);
    initialize_obj_charactere_stat(game, nb, scene);
}

void initialize_obj_particuls(game_t *game, int nb, int scene)
{
    game->scene[scene].object[nb].texture = sfTexture_createFromFile("./assets/sprites/particles/dust_particles_01.png", NULL);
    game->scene[scene].object[nb].sprite = sfSprite_create();
    game->scene[scene].object[nb].scale = (sfVector2f) {3.2, 3.2};
    game->scene[scene].object[nb].position = (sfVector2f) {60, 140};
    game->scene[scene].object[nb].animation = (sfIntRect) {0, 0, 24, 12};
    sfSprite_setTexture(game->scene[scene].object[nb].sprite, game->scene[scene].object[nb].texture, sfTrue);
    sfSprite_setTextureRect(game->scene[scene].object[nb].sprite, game->scene[scene].object[nb].animation);
    sfSprite_setPosition(game->scene[scene].object[nb].sprite, game->scene[scene].object[nb].position);
    sfSprite_setScale(game->scene[scene].object[nb].sprite, game->scene[scene].object[nb].scale);
}

void initialize_obj_map(game_t *game, int nb, int scene)
{
    game->scene[scene].object[nb].texture = sfTexture_createFromFile("./map/realshit.png", NULL);
    game->scene[scene].object[nb].sprite = sfSprite_create();
    game->scene[scene].object[nb].scale = (sfVector2f) {2.5, 2.5};
    game->scene[scene].object[nb].position = (sfVector2f) {0, 0};
    game->scene[scene].object[nb].animation = (sfIntRect) {0, 0, 0, 0};
    sfSprite_setTexture(game->scene[scene].object[nb].sprite, game->scene[scene].object[nb].texture, sfTrue);
    sfSprite_setScale(game->scene[scene].object[nb].sprite, game->scene[scene].object[nb].scale);
    // sfSprite_setTextureRect(game->scene[scene].object[nb].sprite, game->scene[scene].object[nb].animation);
    // sfSprite_setPosition(game->scene[scene].object[nb].sprite, game->scene[scene].object[nb].position);
}

void initialize_timer_one(game_t *game, int nb, int scene)
{
    game->scene[scene].horloge[nb].clock = sfClock_create();
}

void initialize_scene_one(game_t *game)
{
    game->scene = malloc(sizeof(scene_t) * 1);
    game->scene->object = malloc(sizeof(object_t) * 3);
    game->scene->horloge = malloc(sizeof(timer_t) * 2);
    initialize_obj_charactere(game, 0, 0);
    initialize_timer_one(game, 0, 0);
    initialize_obj_particuls(game, 1, 0);
    initialize_obj_map(game, 2, 0);
}

void initialize_view(game_t *game)
{
    game->view = sfView_create();
    sfView_setSize(game->view, (sfVector2f) {1280, 720});
    // sfRenderWindow_setView(game->wdw, game->view);
    // sfView_setCenter(game->view, game->scene->object->position);
}

game_t *initialize_main(void)
{
    game_t *game = malloc(sizeof(game_t));
    game->mode.width = 1280;
    game->mode.height = 720;
    game->mode.bitsPerPixel = 32;
    game->wdw = sfRenderWindow_create(game->mode, "my_rpg",
    sfDefaultStyle, NULL);
    initialize_scene_one(game);
    initialize_view(game);
    return game;
}

void draw_main(game_t *game)
{
    sfRenderWindow_clear(game->wdw, sfBlack);
    sfRenderWindow_drawSprite(game->wdw, game->scene->object[2].sprite, NULL);
    sfRenderWindow_drawSprite(game->wdw, game->scene->object->sprite, NULL);
    sfRenderWindow_drawSprite(game->wdw, game->scene->object[1].sprite, NULL);
    sfRenderWindow_display(game->wdw);
}

void events_charactere_running(game_t *game)
{
    if (game->event.key.code == sfKeyQ ||
    game->event.key.code == sfKeyZ || game->event.key.code == sfKeyS ||
    game->event.key.code == sfKeyD){
        game->scene->object->stat.stat = 2;
    }

    if (game->event.type == sfEvtKeyReleased && game->event.key.code == sfKeyQ
    || game->event.type == sfEvtKeyReleased && game->event.key.code == sfKeyZ
    || game->event.type == sfEvtKeyReleased && game->event.key.code == sfKeyS
    || game->event.type == sfEvtKeyReleased && game->event.key.code == sfKeyD){
        if (game->event.key.code != sfKeyQ || game->event.key.code != sfKeyZ
        || game->event.key.code != sfKeyS || game->event.key.code != sfKeyD){
            game->scene->object->stat.stat = 1;
        }
    }
}

void events_charactere_hitting(game_t *game)
{
    if (game->event.key.code == sfKeySpace){
        game->scene->object->stat.stat = 3;
    }
}

void events_charactere_mooving(game_t *game)
{
        if (sfKeyboard_isKeyPressed(sfKeyZ)){
            game->scene->object->position.y -= 8.5;
        }
        if (sfKeyboard_isKeyPressed(sfKeyQ)){
            game->scene->object->position.x -= 8.5;
        }
        if (sfKeyboard_isKeyPressed(sfKeyS)){
            game->scene->object->position.y += 8.5;
        }
        if (sfKeyboard_isKeyPressed(sfKeyD)){
            game->scene->object->position.x += 8.5;
        }
    sfSprite_setPosition(game->scene->object->sprite,
    game->scene->object->position);
}
int events_main(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->wdw, &game->event)) {
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->wdw);
        events_charactere_running(game);
        events_charactere_hitting(game);
        events_charactere_mooving(game);
    }
}

int rpg(int ac, char **av)
{
    game_t *game = initialize_main();
    sfRenderWindow_setFramerateLimit(game->wdw, 60);
    while (sfRenderWindow_isOpen(game->wdw)){
        sfView_setCenter(game->view, game->scene->object->position);
        sfRenderWindow_setView(game->wdw, game->view);
        events_main(game);
        animation_charactere(game, game->scene->object->stat.stat);
        draw_main(game);
    }
}

int main(int ac, char **av)
{
    rpg(ac, av);
    return 0;
}
