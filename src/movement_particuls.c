/*
** EPITECH PROJECT, 2022
** B-MUL-200-LIL-2-1-myrpg-gabriel.balcon
** File description:
** movement_particuls
*/

#include "../include/file.h"

void movements_particul(game_t *game)
{
    game->scene->object[1].animation.left += 24;
    if (game->scene->object[1].animation.left >= 36)
        game->scene->object[1].animation.left = 0;
    sfSprite_setTextureRect(game->scene->object[1].sprite, game->scene->object
    [1].animation);
}
