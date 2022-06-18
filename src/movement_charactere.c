/*
** EPITECH PROJECT, 2022
** B-MUL-200-LIL-2-1-myrpg-gabriel.balcon
** File description:
** movement
*/

#include "../include/file.h"

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
    sfSprite_setTextureRect(game->scene->object[0].sprite, game->scene->
    object[0].animation);
}
