/*
** EPITECH PROJECT, 2022
** B-MUL-200-LIL-2-1-myrpg-gabriel.balcon
** File description:
** initialize_charactere
*/

#include "../include/file.h"

void initialize_obj_charactere_stat(game_t *game, int nb, int scene)
{
    game->scene[scene].object->stat.stat = 1;
}

void initialize_obj_charactere_one(game_t *game, int nb, int scene)
{
    sfSprite_setTexture(game->scene[scene].object[nb].sprite, game->scene
    [scene].object[nb].texture, sfTrue);
    sfSprite_setTextureRect(game->scene[scene].object[nb].sprite, game->scene
    [scene].object[nb].animation);
    sfSprite_setPosition(game->scene[scene].object[nb].sprite, game->scene
    [scene].object[nb].position);
    sfSprite_setScale(game->scene[scene].object[nb].sprite, game->scene[scene]
    .object[nb].scale);
    sfRectangleShape_setPosition(game->scene[scene].object->rect, (sfVector2f) {game->scene->object->hitbox.left, game->scene->object->hitbox.top});
    sfRectangleShape_setSize(game->scene[scene].object->rect, (sfVector2f) {game->scene->object->hitbox.width, game->scene->object->hitbox.height});
    sfRectangleShape_setOutlineThickness(game->scene[scene].object->rect,
    0.65);
    sfRectangleShape_setOutlineColor(game->scene[scene].object->rect,
    sfBlack);
    sfRectangleShape_setFillColor(game->scene[scene].object[nb].rect,
    sfTransparent);
    initialize_obj_charactere_stat(game, nb, scene);
}

void initialize_obj_charactere(game_t *game, int nb, int scene)
{
    game->scene[scene].object[nb].texture =
    sfTexture_createFromFile("./assets/sprites/characters/player.png", NULL);
    game->scene[scene].object[nb].sprite = sfSprite_create();
    game->scene[scene].object[nb].scale = (sfVector2f) {1, 1};
    game->scene[scene].object[nb].position = (sfVector2f) {50, 50};
    game->scene[scene].object[nb].position_hitbox = (sfVector2f)
    {game->scene[scene].object[nb].position.x + 24, game->scene[scene].object
    [nb].position.y + 22};
    game->scene[scene].object[nb].animation = (sfIntRect) {0, 16, 48, 32};
    game->scene[scene].object[nb].hitbox = (sfIntRect) {game->scene->object->position_hitbox.x, game->scene->object->position_hitbox.y, 20, 10};
    game->scene[scene].object[nb].rect = sfRectangleShape_create();
    initialize_obj_charactere_one(game, scene, nb);
}