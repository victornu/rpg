/*
** EPITECH PROJECT, 2022
** B-MUL-200-LIL-2-1-myrpg-gabriel.balcon
** File description:
** initialize_particuls
*/

#include "../include/file.h"

void initialize_obj_particuls(game_t *game, int nb, int scene)
{
    game->scene[scene].object[nb].texture = sfTexture_createFromFile
    ("./assets/sprites/particles/dust_particles_01.png", NULL);
    game->scene[scene].object[nb].sprite = sfSprite_create();
    game->scene[scene].object[nb].scale = (sfVector2f) {1, 1};
    game->scene[scene].object[nb].position = (sfVector2f) {60, 140};
    game->scene[scene].object[nb].animation = (sfIntRect) {0, 0, 24, 12};
    sfSprite_setTexture(game->scene[scene].object[nb].sprite, game->scene
    [scene].object[nb].texture, sfTrue);
    sfSprite_setTextureRect(game->scene[scene].object[nb].sprite, game->
    scene[scene].object[nb].animation);
    sfSprite_setPosition(game->scene[scene].object[nb].sprite, game->
    scene[scene].object[nb].position);
    sfSprite_setScale(game->scene[scene].object[nb].sprite, game->
    scene[scene].object[nb].scale);
}
